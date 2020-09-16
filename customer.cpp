#include <iostream>
using namespace std;

// #ifndef Customer
// #define CUSTOMER

class Customer
{
private:
    string customerID = "NUll";
    int arrival_time=999;
    int priority=999;
    int age=999;
    int ticket_num=999;  // ticket number require  e.g. 50

    int original_priority;
    int original_ticket_num;  //never change the copy

    int times_of_run = 0; // number of times it runs  ONLY USE IN QUEUE1
    int end = 0;
    int ready_time = 888; //when does the customer ready, all ticket required are addressed
    int running = 0;  // runnign time
    int waiting = 0; //waiting time
    bool if_first_run = false;

    int span_time_in_queue2 = 0;
    int time_since_last_run;  // in queue2



public:
    //default constructor
    Customer() 
    {
        customerID = "NULL"; 
        arrival_time = 999; 
        priority = 999; 
        age = 999; 
        ticket_num = 999;
    }
    //user define constructor
    Customer(string customerID_, int arrival_time_, int priority_, int age_, int ticket_num_)
    {
        customerID = customerID_;
        arrival_time = arrival_time_;
        priority = priority_;
        age = age_;
        ticket_num = ticket_num_;
    }

    // get methods
    string get_customerID() const {return customerID;}
    int get_arrival_time() const {return arrival_time;}
    int get_priority() const {return priority;}
    int get_age() const {return age;}
    int get_ticket_num() const {return ticket_num;}

    int get_times_of_run() {return times_of_run;}
    int get_ready_time() {return ready_time;}
    int get_running_time() {return running;}
    int get_waiting_time() {return end-ready_time-running;}
    bool get_if_first_run() {return if_first_run;}
    int get_original_priority_num() {return original_priority;}
    int get_original_ticket_num() {return original_ticket_num;}
    int get_time_since_last_run() {return time_since_last_run;}
    int get_span_time_in_queue2() {return span_time_in_queue2;}

    // set methods
    void set_customerID(string new_ID){customerID = new_ID;}
    void set_arrival_time(int new_arrival_time) {arrival_time=new_arrival_time;}
    void set_priority(int new_priority) {priority = new_priority;}
    void set_age(int new_age){age = new_age;}
    void set_ticket_num(int new_ticket_num){ticket_num=new_ticket_num;}
    void set_ready_time(int ready_time_) {ready_time = ready_time_;}
    void set_original_ticket_num() {original_ticket_num = ticket_num;}
    void set_original_priority_num() {original_priority = priority;}
    void reset_span_time_in_queue2() {span_time_in_queue2 = 0;}
    

    void add_one_time_of_run() {times_of_run++;}
    void minus_update_priority() {priority--;}  //be more prior
    void plus_update_priority() {priority++;}   //be more susequent
    void update_ticket_num(int N) {ticket_num -= N;}


    void set_end(int current_time) {end = current_time;}
    int get_end() {return end;}
    void set_if_first_run(bool bool_) {if_first_run = bool_;}

    void update_ready_time(int added_time) {ready_time += added_time;}
    void update_running_time(int added_running_time) {running += added_running_time;}
    void update_span_time_in_queue2(int added_span_time) {span_time_in_queue2 += added_span_time;}
    void reset_times_of_run() {times_of_run = 0;}
    void update_time_since_last_run(int added_time) {time_since_last_run += added_time;}  // queue2
    void reset_time_since_last_run(int time_since_last_run_)  //reset time_since_last_run to 0
    {
        if (time_since_last_run_ == 100)
            time_since_last_run = 0;
    }


};
