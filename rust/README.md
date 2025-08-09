# SFST Rust Binding

This is a Rust binding for the SFST (Stuttgart Finite State Transducer Tools) library. It provides a safe, idiomatic Rust interface to the C++ SFST library for finite state transducer operations.

## Features

- **Safe API**: Memory-safe Rust wrapper around the C++ SFST library
- **Two API styles**: Functional API and RAII-style API for automatic resource management
- **Error handling**: Comprehensive error types with descriptive messages
- **Python-compatible**: API mirrors the existing Python binding

## Prerequisites

- Rust toolchain (1.70+)
- C++ compiler (g++ or clang++)
- SFST source files (should be in `../src/` relative to this directory)

## Building

1. Clone or place this `rust/` directory alongside the SFST source code:
   ```
   project/
   ├── src/           # SFST C++ source files
   ├── python/        # Python bindings (optional)
   └── rust/          # This Rust binding
   ```

2. Build the library:
   ```bash
   cd rust
   cargo build
   ```

3. Run tests:
   ```bash
   cargo test
   ```

4. Run the example/test binary:
   ```bash
   cargo run --bin main
   ```

## Usage

### Functional API

```rust
use sfst;

// Initialize transducer from file
sfst::init("path/to/transducer.a")?;

// Analyze a surface form
let analysis = sfst::analyse("easier")?;
println!("Analysis: {:?}", analysis); // ["easy<ADJ><comp>"]

// Generate a surface form
let generation = sfst::generate("easy<ADJ><comp>")?;
println!("Generation: {:?}", generation); // ["easier"]

// Manual cleanup
sfst::cleanup();
```

### RAII API (Recommended)

```rust
use sfst::Sfst;

// Initialize with automatic cleanup
let sfst = Sfst::new("path/to/transducer.a")?;

// Analyze and generate
let analysis = sfst.analyse("easier")?;
let generation = sfst.generate("easy<ADJ><comp>")?;

// Automatic cleanup when `sfst` goes out of scope
```

### Error Handling

```rust
use sfst::{Sfst, SfstError};

match Sfst::new("transducer.a") {
    Ok(sfst) => {
        match sfst.analyse("word") {
            Ok(results) => println!("Results: {:?}", results),
            Err(SfstError::TransducerNotInitialized) => {
                eprintln!("Transducer not properly initialized");
            }
            Err(e) => eprintln!("Error: {}", e),
        }
    }
    Err(SfstError::FileError(msg)) => {
        eprintln!("Could not load transducer: {}", msg);
    }
    Err(e) => eprintln!("Error: {}", e),
}
```

## API Reference

### Functions

- `init(filename: &str) -> Result<(), SfstError>` - Initialize transducer from file
- `analyse(input: &str) -> Result<Vec<String>, SfstError>` - Analyze a string
- `generate(input: &str) -> Result<Vec<String>, SfstError>` - Generate a string
- `cleanup()` - Manual cleanup (not needed with RAII API)

### RAII Wrapper

- `Sfst::new(filename: &str) -> Result<Sfst, SfstError>` - Create with automatic cleanup
- `sfst.analyse(input: &str) -> Result<Vec<String>, SfstError>` - Analyze a string
- `sfst.generate(input: &str) -> Result<Vec<String>, SfstError>` - Generate a string

### Error Types

```rust
pub enum SfstError {
    InvalidInput(String),     // Invalid input parameters
    FileError(String),        // File loading/reading errors
    TransducerNotInitialized, // Transducer not initialized
    AllocationError,          // Memory allocation failure
}
```

## File Structure

```
rust/
├── Cargo.toml              # Package configuration
├── README.md               # This file
├── build.rs                # Build script for C++ compilation
└── src/
    ├── lib.rs              # Main library code
    ├── main.rs             # Example/test binary
    ├── sfst_wrapper.h      # C header for FFI
    └── sfst_wrapper.cpp    # C++ wrapper implementation
```

## Testing

The crate includes comprehensive tests that mirror the Python test suite:

```bash
# Run library tests
cargo test

# Run the example binary (requires test files)
cargo run --bin main
```

The tests expect the test file `python/tests/easy.a` to exist. Make sure you have the complete SFST project structure.

## Compatibility

This binding is designed to be API-compatible with the Python SFST binding, making it easy to port existing Python code to Rust:

**Python:**
```python
import sfst
sfst.init("transducer.a")
results = sfst.analyse("word")
```

**Rust:**
```rust
use sfst;
sfst::init("transducer.a")?;
let results = sfst::analyse("word")?;
```

## Safety

- All C++ memory management is handled safely
- Automatic cleanup prevents memory leaks
- Null pointer checks and error handling
- Safe string conversions between Rust and C++

## License

This binding follows the same license as the original SFST library.
