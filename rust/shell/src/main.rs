use std::io::stdin;
use std::io::stdout;
use std::process::Command;
use std::io::Write;

fn  main(){
    let prompt = "$ ";

    loop {
        print!("{}", prompt);
        stdout().flush();
        let mut input = String::new(); 
        stdin().read_line(&mut input).unwrap();

        let command = input.trim();
        let command: Vec<_> = command.split(" ").collect();
        let mut child = Command::new(command[0]);

        for (i, arg) in command.iter().enumerate() {
            if i == 0 {
                continue;
            }
            child.arg(arg);
        }
        
        child.spawn();


    }

}
