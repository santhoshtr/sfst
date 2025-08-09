use clap::{Parser, Subcommand};
use std::path::PathBuf;

#[derive(Parser)]
#[command(name = "sfst")]
#[command(about = "SFST (Stuttgart Finite State Transducer) CLI tool")]
#[command(version = "0.1.0")]
struct Cli {
    #[command(subcommand)]
    command: Commands,
}

#[derive(Subcommand)]
enum Commands {
    /// Analyze input text
    Analyse {
        /// Path to the transducer file (.a file)
        #[arg(short, long)]
        transducer: PathBuf,
        /// Text to analyze
        text: String,
    },
    /// Generate text from morphological representation
    Generate {
        /// Path to the transducer file (.a file)
        #[arg(short, long)]
        transducer: PathBuf,
        /// Morphological representation to generate from
        text: String,
    },
}

fn main() {
    let cli = Cli::parse();

    // Process the command
    let result = match &cli.command {
        Commands::Analyse { transducer, text } => {
            // Check if transducer file exists
            if !transducer.exists() {
                eprintln!("Error: Transducer file not found: {:?}", transducer);
                std::process::exit(1);
            }

            // Initialize the transducer
            match sfst::init(transducer.to_str().unwrap()) {
                Ok(_) => {
                    if std::env::var("VERBOSE").is_ok() {
                        eprintln!("✓ Transducer loaded successfully from {:?}", transducer);
                    }
                }
                Err(e) => {
                    eprintln!("Error: Failed to load transducer: {}", e);
                    std::process::exit(1);
                }
            }

            match sfst::analyse(text) {
                Ok(results) => {
                    if results.is_empty() {
                        eprintln!("No analysis found for: {}", text);
                        std::process::exit(1);
                    } else {
                        for result in results {
                            println!("{}", result);
                        }
                        Ok(())
                    }
                }
                Err(e) => {
                    eprintln!("Error during analysis: {}", e);
                    Err(e)
                }
            }
        }
        Commands::Generate { transducer, text } => {
            // Check if transducer file exists
            if !transducer.exists() {
                eprintln!("Error: Transducer file not found: {:?}", transducer);
                std::process::exit(1);
            }

            // Initialize the transducer
            match sfst::init(transducer.to_str().unwrap()) {
                Ok(_) => {
                    if std::env::var("VERBOSE").is_ok() {
                        eprintln!("✓ Transducer loaded successfully from {:?}", transducer);
                    }
                }
                Err(e) => {
                    eprintln!("Error: Failed to load transducer: {}", e);
                    std::process::exit(1);
                }
            }

            match sfst::generate(text) {
                Ok(results) => {
                    if results.is_empty() {
                        eprintln!("No generation found for: {}", text);
                        std::process::exit(1);
                    } else {
                        for result in results {
                            println!("{}", result);
                        }
                        Ok(())
                    }
                }
                Err(e) => {
                    eprintln!("Error during generation: {}", e);
                    Err(e)
                }
            }
        }
    };

    // Cleanup
    sfst::cleanup();

    // Exit with appropriate code
    if result.is_err() {
        std::process::exit(1);
    }
}
