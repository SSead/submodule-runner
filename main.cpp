#include <iostream>
#include <vector>
#include <fstream>

std::string x = "";

void welcome();
void submodule(std::vector<std::string>&);
void commitpush(std::vector<std::string>&);
void commit(std::vector<std::string>&);
void push(std::vector<std::string>&);
void commitpushnewbranch(std::vector<std::string>&);


main(int argc, char **argv) {

    //Creating a vector of all the argments
    std::vector<std::string> arg;
    for (int i = 0; i < argc; i++) arg.push_back(*(argv + i));


    //Checking if there are no aditional arguments
    if (argc == 1) {

        //Run welcome page
        welcome();
    } else {

        //Run the submodule program
        submodule(arg);
    }
}

//Welcome page
void welcome() {
    std::cout 
        << "Welcome to the submodule runner. This libray helps you manage submodule with git\n"
        << "Try out some of the commands we have integrated:\n"
        << "    commit\n"
        << "    push\n"
        << "    commitpush \n";
}

void submodule(std::vector<std::string>& arg) {

    //Checking for the first argument
    if (arg[1] == "commitpush") {

        //Commit push
        commitpush(arg);

    } else if (arg[1] == "commit") {

        //Commit
        commit(arg);

    } else if (arg[1] == "push") {

        //Push
        push(arg);

    } else if (arg[1] == "commitpushnewbranch") {

        std::cout << "WIP\n";
        //commitpushnewbranch(arg);

    } else if (arg[1] == "--help" || arg[1] == "-h") {

        welcome();

    } else {

        //Unrecognized parametar
        std::cout << "Parametar does not exist.\n";
    }
}

void commitpush(std::vector<std::string>& arg) {
    if (arg.size() == 2) {
        std::cout << "error: Missing paramater. Add --help to paramaters.\n";

    } else if (arg[2] == "-m"){

        if (arg.size() == 3) {

            std::cout 
                << "Missing parametar:\n"
                << "    --m <commit-message>\n";

        } else {
            system((x + "git submodule foreach \"(git add --all && git commit -m '" + arg[3] + "' && git push) || :\"").c_str());
            system("git add --all");
            system(("git commit -m \"" + arg[3] + "\"").c_str());
            system("git push");
        }
        
    } else if (arg[2] == "--help") {


        std::cout 
            << "Currentry integrated paramaters:\n"
            << "    --m <commit-message>\n";
    
    } else if (arg[2] == "--amend") {
        system("git submodule foreach \"(git add --all && git commit --amend --no-edit && git push -f) || :\"");
        system("git add --all");
        system("git commit --amend --no-edit");
        system("git push -f");
    }
}

void commit(std::vector<std::string>& arg) {
    if (arg.size() == 2) {

        std::cout << "error: Missing paramater. Add --help to see paramaters.\n";

    } else if (arg[2] == "-m"){

        if (arg.size() == 3) {
            
            std::cout 
                << "Missing parametar:\n"
                << "    --m <commit-message>\n";

        } else {
            system((x + "git submodule foreach \"(git add --all && git commit -m '" + arg[3] + "') || :\"").c_str());
            system("git add --all");
            system(("git commit -m \"" + arg[3] + "\"").c_str());
        }
        
    } else if (arg[2] == "--help") {

        std::cout 
            << "Currentry integrated paramaters:\n"
            << "    --m <commit-message>\n";
    
    }
}

void push(std::vector<std::string>& arg) {
    system((x+"git submodule foreach \"git push || :\"").c_str());
    system("git push");
}

void commitpushnewbranch(std::vector<std::string>& arg) {
    
}