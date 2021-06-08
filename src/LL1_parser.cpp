#include "LL1_parser.h"
#include <stack>

LL1_parser:: LL1_parser(string first_NonTerminal, unordered_map<string, unordered_set<string>*>* first_set,
        unordered_map<string, unordered_set<string>*>* follow_set,vector<pair<string,vector<string>*>>* Grammar,
        unordered_set<string>* Terminals, unordered_set<string>* Nonterminals){

            //initialize pointer to first non terminal
            this->frist_nonterminal = first_NonTerminal;

            //create parsing table and using first and follow sets, and the grammar. Then initialize a pointer to the created table.
            table * created_table = new table(first_set,follow_set,Grammar,Terminals);
            this->parseing_table = created_table;
            if(!this->parseing_table->is_valid()){
                cout<<"ERROR"<<endl;
                this->parseing_table->delete_table();
                delete(this->parseing_table);
                /*
                *
                *
                * Error handeling
                * 
                * 
                */
            }

            //initialize pointers to sets of terminals and nonterminals
            this->nonterminals = Nonterminals;
            this->terminals = Terminals;

}

bool LL1_parser:: validate_syntax(vector<string> input){
    
    //Garantees that at the end of input stream there is a '$'
    int input_size = input.size();
    if(input.at(input_size-1) != "$"){
        input.push_back("$");
        input_size++;
    }

    //Initialize stack
    stack<string> parsing_stack;
    parsing_stack.push("$");
    parsing_stack.push(frist_nonterminal);

    int current_token = 0;

    while(parsing_stack.top() != "$" && current_token < input_size){
        //if top of the stack is a terminal
        if(terminals->find(parsing_stack.top()) != terminals->end()){
            if(parsing_stack.top() == input.at(current_token)){
                current_token++;
                parsing_stack.pop();
            }
            else{
                return false; 
            }
        }
        //if top of the stack is a non terminal
        else if(nonterminals->find(parsing_stack.top()) != nonterminals->end()){
            //get from the table the equavilent production of this nonterminal with the given terminal as input
            string production = parseing_table->get_production(parsing_stack.top(),input.at(current_token));
            if(production == "ERROR"){
                return false;
            }
            cout<< parsing_stack.top()<<" --> "<<production<<endl;
            //pop non terminal
            parsing_stack.pop();
            //add to the stack its possible production terms
            vector<string>* terms_of_production = split_string(production);
            for(auto term: *terms_of_production){
                parsing_stack.push(term);
            }
        }
        else{
            return false;
        }
    }
    cout<<"Process terminated successfully"<<endl;
    return true;
}