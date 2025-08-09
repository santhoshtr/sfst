use std::ffi::{CStr, CString};
use std::os::raw::{c_char, c_int};

#[link(name = "sfst_wrapper", kind = "static")]
unsafe extern "C" {
    fn sfst_init(filename: *const c_char) -> c_int;
    fn sfst_cleanup();
    fn sfst_analyse(input: *const c_char, result_count: *mut c_int) -> *mut *mut c_char;
    fn sfst_generate(input: *const c_char, result_count: *mut c_int) -> *mut *mut c_char;
    fn sfst_free_results(results: *mut *mut c_char, count: c_int);
}

#[derive(Debug)]
pub enum SfstError {
    InvalidInput(String),
    FileError(String),
    TransducerNotInitialized,
    AllocationError,
}

impl std::fmt::Display for SfstError {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        match self {
            SfstError::InvalidInput(msg) => write!(f, "Invalid input: {}", msg),
            SfstError::FileError(msg) => write!(f, "File error: {}", msg),
            SfstError::TransducerNotInitialized => write!(f, "Transducer not initialized"),
            SfstError::AllocationError => write!(f, "Memory allocation error"),
        }
    }
}

impl std::error::Error for SfstError {}

/// Initialize the SFST transducer from a file
pub fn init(filename: &str) -> Result<(), SfstError> {
    let c_filename = CString::new(filename)
        .map_err(|_| SfstError::InvalidInput("Filename contains null bytes".to_string()))?;

    let result = unsafe { sfst_init(c_filename.as_ptr()) };

    match result {
        0 => Ok(()),
        1 => Err(SfstError::InvalidInput("Filename is null".to_string())),
        2 => Err(SfstError::FileError("Could not open file".to_string())),
        3 => Err(SfstError::FileError("Error loading transducer".to_string())),
        _ => Err(SfstError::FileError("Unknown error".to_string())),
    }
}

/// Analyze a string using the loaded transducer
pub fn analyse(input: &str) -> Result<Vec<String>, SfstError> {
    let c_input = CString::new(input)
        .map_err(|_| SfstError::InvalidInput("Input contains null bytes".to_string()))?;

    let mut result_count: c_int = 0;
    let results = unsafe { sfst_analyse(c_input.as_ptr(), &mut result_count) };

    if results.is_null() {
        if result_count == 0 {
            return Ok(Vec::new());
        } else {
            return Err(SfstError::AllocationError);
        }
    }

    let mut rust_results = Vec::with_capacity(result_count as usize);

    for i in 0..result_count {
        let c_str_ptr = unsafe { *results.offset(i as isize) };
        if c_str_ptr.is_null() {
            unsafe { sfst_free_results(results, result_count) };
            return Err(SfstError::AllocationError);
        }

        let c_str = unsafe { CStr::from_ptr(c_str_ptr) };
        let rust_string = c_str.to_string_lossy().into_owned();
        rust_results.push(rust_string);
    }

    unsafe { sfst_free_results(results, result_count) };
    Ok(rust_results)
}

/// Generate a string using the loaded transducer
pub fn generate(input: &str) -> Result<Vec<String>, SfstError> {
    let c_input = CString::new(input)
        .map_err(|_| SfstError::InvalidInput("Input contains null bytes".to_string()))?;

    let mut result_count: c_int = 0;
    let results = unsafe { sfst_generate(c_input.as_ptr(), &mut result_count) };

    if results.is_null() {
        if result_count == 0 {
            return Ok(Vec::new());
        } else {
            return Err(SfstError::AllocationError);
        }
    }

    let mut rust_results = Vec::with_capacity(result_count as usize);

    for i in 0..result_count {
        let c_str_ptr = unsafe { *results.offset(i as isize) };
        if c_str_ptr.is_null() {
            unsafe { sfst_free_results(results, result_count) };
            return Err(SfstError::AllocationError);
        }

        let c_str = unsafe { CStr::from_ptr(c_str_ptr) };
        let rust_string = c_str.to_string_lossy().into_owned();
        rust_results.push(rust_string);
    }

    unsafe { sfst_free_results(results, result_count) };
    Ok(rust_results)
}

/// Clean up the transducer
pub fn cleanup() {
    unsafe { sfst_cleanup() };
}

/// RAII wrapper for automatic cleanup
pub struct Sfst {
    _private: (),
}

impl Sfst {
    /// Initialize transducer from file with automatic cleanup
    pub fn new(filename: &str) -> Result<Self, SfstError> {
        init(filename)?;
        Ok(Sfst { _private: () })
    }

    /// Analyze a string
    pub fn analyse(&self, input: &str) -> Result<Vec<String>, SfstError> {
        analyse(input)
    }

    /// Generate a string
    pub fn generate(&self, input: &str) -> Result<Vec<String>, SfstError> {
        generate(input)
    }
}

impl Drop for Sfst {
    fn drop(&mut self) {
        cleanup();
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::env;
    use std::path::PathBuf;

    fn get_test_file_path() -> PathBuf {
        let manifest_dir = env::var("CARGO_MANIFEST_DIR").unwrap();
        PathBuf::from(manifest_dir)
            .parent()
            .unwrap()
            .join("rust")
            .join("test")
            .join("easy.a")
    }

    #[test]
    fn test_functional_api() {
        let test_file = get_test_file_path();

        init(test_file.to_str().unwrap()).unwrap();

        let analysis_results = analyse("easy").unwrap();
        assert_eq!(analysis_results.len(), 1);
        assert_eq!(analysis_results[0], "easy<ADJ><pos>");

        let generate_results = generate("easy<ADJ><comp>").unwrap();
        assert_eq!(generate_results.len(), 1);
        assert_eq!(generate_results[0], "easier");

        cleanup();
    }

    #[test]
    fn test_raii_api() {
        let test_file = get_test_file_path();

        let sfst = Sfst::new(test_file.to_str().unwrap()).unwrap();

        let analysis_results = sfst.analyse("easy").unwrap();
        assert_eq!(analysis_results.len(), 1);
        assert_eq!(analysis_results[0], "easy<ADJ><pos>");

        let generate_results = sfst.generate("easy<ADJ><comp>").unwrap();
        assert_eq!(generate_results.len(), 1);
        assert_eq!(generate_results[0], "easier");

        // Automatic cleanup when sfst goes out of scope
    }
}
