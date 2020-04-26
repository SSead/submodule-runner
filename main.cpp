#include <iostream>
#include <vector>

std::string x = "";

void welcome();
void submodule(std::vector<std::string>&);
void commitpush(std::vector<std::string>&);
void commit(std::vector<std::string>&);
void push(std::vector<std::string>&);


main(int argc, char **argv) {
    std::vector<std::string> arg;
    for (int i = 0; i < argc; i++) arg.push_back(*(argv + i));

    if (argc == 1) {
        welcome();
    } else {
        submodule(arg);
    }
}

void welcome() {
    std::cout 
        << "Welcome to the submodule runner. This libray helps you manage submodule with git\n"
        << "Try out some of the commands we have integrated:\n"
        << "    commit\n"
        << "    push\n"
        << "    commitpush \n";
}

void submodule(std::vector<std::string>& arg) {

    if (arg[1] == "commitpush") {
        commitpush(arg);
    } else if (arg[1] == "commit") {
        commit(arg);
    } else if (arg[1] == "push") {
        push(arg);
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
            system((x + "git submodule foreach \"git commit -m '" + arg[3] + "' -a \"").c_str());
            system((x + "git commit -m \"" + arg[3] + "\"").c_str());
            
            system("git submodule foreach \"git push origin master\"");
            system("git push origin master");
            
        }
        
    } else if (arg[2] == "--help") {

        std::cout 
            << "Currentry integrated paramaters:\n"
            << "    --m <commit-message>\n";
    
    }
}

void commit(std::vector<std::string>& arg) {
    if (arg.size() == 2) {

        std::cout << "error: Missing paramater. Add --help to paramaters.\n";

    } else if (arg[2] == "-m"){

        if (arg.size() == 3) {
            
            std::cout 
                << "Missing parametar:\n"
                << "    --m <commit-message>\n";

        } else {
            system((x + "git submodule foreach \"git commit -m '" + arg[3] + "' -a \"").c_str());
            system((x + "git commit -m \"" + arg[3] + "\"").c_str());
            
        }
        
    } else if (arg[2] == "--help") {

        std::cout 
            << "Currentry integrated paramaters:\n"
            << "    --m <commit-message>\n";
    
    }
}

void push(std::vector<std::string>& arg) {
    system("git submodule foreach \"git push origin master\"");
    system("git push origin master");
}