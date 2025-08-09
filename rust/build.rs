use std::env;
use std::path::PathBuf;

fn main() {
    let manifest_dir = env::var("CARGO_MANIFEST_DIR").unwrap();
    let src_dir = PathBuf::from(&manifest_dir).parent().unwrap().join("src");

    // Build the C++ wrapper
    cc::Build::new()
        .cpp(true)
        .file("src/sfst_wrapper.cpp")
        .include(&src_dir) // Include the parent src directory for SFST headers
        .flag("-std=c++11")
        .compile("sfst_wrapper");

    // Build the SFST library with all required source files
    let mut build = cc::Build::new();
    build.cpp(true).include(&src_dir).flag("-std=c++11");

    // Add all the SFST source files
    let source_files = [
        "fst.cpp",
        "alphabet.cpp",
        "basic.cpp",
        "compact.cpp",
        "determinise.cpp",
        "hopcroft.cpp",
        "interface.cpp",
        "operators.cpp",
        "utf8.cpp",
    ];

    for file in &source_files {
        let file_path = src_dir.join(file);
        if file_path.exists() {
            build.file(file_path);
            println!("cargo:rerun-if-changed=../src/{}", file);
        } else {
            println!("cargo:warning=Missing source file: {}", file);
        }
    }

    build.compile("sfst");

    // Tell Cargo to link the compiled libraries
    println!("cargo:rustc-link-lib=static=sfst_wrapper");
    println!("cargo:rustc-link-lib=static=sfst");

    // Link the C++ standard library
    println!("cargo:rustc-link-lib=stdc++");

    println!("cargo:rerun-if-changed=src/sfst_wrapper.cpp");
    println!("cargo:rerun-if-changed=src/sfst_wrapper.h");
}
