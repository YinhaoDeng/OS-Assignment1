/*
created by: Yinhao Deng, Chenyu Mei
ID: a1731310, a1752385
Contact Email: yinhao.deng@student.adelaide.edu.au
               chenyu.mei@student.adelaide.edu.au
-----------------------------------------------------
input sample:
ID arrival_time priority age total_tickets_required
for example: s1 3 1 0 50

output sample:
ID, arrival and termination times, ready time and durations of running and waiting
*/

#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
#include "queue.cpp"


const int array_size = 15;
// const int 
// Customer* customer_arr[array_size];  // this can be seen as arrive order. array type must be Customer instead of string
Customer customer_0, customer_1, customer_2, customer_3, customer_4, customer_5, customer_6, customer_7, customer_8, customer_9;
vector <Customer*> customer_vec;

queue<Customer*> queue1; // high-priority queue   priority <=3
vector<Customer*> queue1_pool;
vector<Customer*> queue2;// low-priority queue priority >=4

queue<Customer*> output_queue;

// 时钟 clock
int timer = 0;

void initial()
{
    string line; // for reading cin only
    int customer_arr_idx = 0;
    string customerID, arrival_time, priority, age, ticket_num; // for cin convinience, all varialbles are string type instead of int

    do{
        // MUST re-initialise these varialbes when read new line of cin
        customerID="", arrival_time="", priority="", age="", ticket_num="";
        
        cin>>customerID>>arrival_time>>priority>>age>>ticket_num;


        // string customer = "customer";
        // int i = 0;
        // string customer_name = customer + to_string(i);
        // Customer customer_name;

        //vector part
        // if(customerID == ""||arrival_time==""||priority=="")
        // {
        //     Customer customer = Customer(); 
        //     customer_vec.push_back(&customer);
        //     // delete &customer;
        // }else
        // {
        //     Customer customer = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
        //     customer_vec.push_back(&customer);
        //     // delete &customer;
        // }

        //array part
        if (customer_arr_idx==0&&priority!="")
        {
            customer_0 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_0);
        }else if(customer_arr_idx==1&&priority!="")
        {
            customer_1 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_1);
        }else if(customer_arr_idx==2&&priority!="")
        {
            customer_2 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_2);
        }else if(customer_arr_idx==3&&priority!="")
        {
            customer_3 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_3);
        }else if(customer_arr_idx==4&&priority!="")
        {    
            customer_4 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_4);
        }else if(customer_arr_idx==5&&priority!="")
        {    
            customer_5 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_5);
        }else if(customer_arr_idx==6&&priority!="")
        {    
            customer_6 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_6);
        }else if(customer_arr_idx==7&&priority!="")
        {    
            customer_7 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_7);
        }else if(customer_arr_idx==8&&priority!="")
        {    
            customer_8 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_8);
        }else if(customer_arr_idx==9&&priority!="")
        {    
            customer_9 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_9);
        }else
        {
            customer_vec.push_back(&customer_9);
        }
        
        // }else if(customer_arr_idx==5&&priority!="")
        // {    
        //     customer_5 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
        //     // customer_arr[4] = &customer_4;
        //     customer_vec.push_back(&customer_5);
        // }
        // }else
        // {
        //     // customer_arr[3] = &customer_3;
        //     customer_vec.push_back(&customer_4);
        //     // // customer_arr[4] = &customer_4;
        //     customer_vec.push_back(&customer_5);
        // }
        
        // if(customer_arr_idx > array_size-1) 
        //     break;

        if(customer_arr_idx > 10) 
        {
            cout<<"shit"<<endl;
            break;
        }

        cout<<"index: "<<customer_arr_idx<<endl;
      
        //cout for debugging use
        cout<<"customer_"<<customer_arr_idx<<" address:"<<&customer_vec[customer_arr_idx]<<endl;
        cout<<"Original input: \n"<<customerID<<' '<<arrival_time<<' '<<priority<<' '<<age<<' '<<ticket_num<<endl;
        cout<<"Processed input(read from memory): \n"<<customer_vec[customer_arr_idx]->get_customerID()<<' '<<customer_vec[customer_arr_idx]->get_arrival_time()
        <<' '<<customer_vec[customer_arr_idx]->get_priority()<<' '<<customer_vec[customer_arr_idx]->get_age()<<' '<<customer_vec[customer_arr_idx]->get_ticket_num()<<endl;

        cout<<"------------------------------------"<<endl;

        customer_arr_idx++;  //update customer_arr index
        
    }while (getline(cin,line));

    for (int j=0; j<customer_vec.size(); j++)
    {
        cout<<"j:"<<j<<'|';
        cout<<customer_vec[j]->get_customerID()<<" ";
    }
    cout<<endl;
    //基础sort
    customer_vec = sort_customer_vec_based_on_arrival_time(customer_vec);
    cout<<"sorted customer_vec (based on arrival_time)"<<endl;
    for (int j=0; j<customer_vec.size(); j++)
    {
        cout<<"j:"<<j<<'|';
        cout<<customer_vec[j]->get_customerID()<<" ";
    }
}



void input()
{ 
    // cout<<"queue1 (from head to tail): ";
    // while (!queue1.empty())
    // {
    //     cout << queue1.front()->get_customerID() << " ";
    //     queue1.pop();
    // }
    // cout<<endl;
    
    //testing sort_queue2() function
    // queue2 = sort_queue2(queue2); //脱胎换骨
    // cout<<"queue2 (from head to tail): ";
    // for (int j=0; j<queue2.size(); j++)
    // {
    //     cout<<queue2[j]->get_customerID()<<" ";
    // }

}


bool check_any_new_arrival_customer_each_5_sec()
{
    if(customer_vec[0]->get_arrival_time() != timer || customer_vec.size()==0)
    {
        return false;
    }
    else if(customer_vec[0]->get_arrival_time() == timer && customer_vec.size()!=0)
    {
    // dispatch customer into queue1_pool or queue2 based on their
        while(customer_vec[0]->get_arrival_time() == timer && customer_vec.size()!=0)  
        {
            cout<<"customer_vec[0]: "<<customer_vec[0]->get_customerID()<<endl;
            if(customer_vec[0]->get_priority() <= 3)
            {
                cout<<"push "<<customer_vec[0]->get_customerID()<<" into queue1_pool.    ";
                queue1_pool.push_back(customer_vec[0]);     //queue1缓存池
                
                cout<<"erase "<<customer_vec[0]->get_customerID()<<endl;
                customer_vec.erase(customer_vec.begin());
                cout<<"````````````````````````````````"<<endl;

            }else if(customer_vec[0]->get_priority() >= 4)
            {
                cout<<"push "<<customer_vec[0]->get_customerID()<<" into queue2.    ";
                queue2.push_back(customer_vec[0]);
                
                queue2 = sort_queue2(queue2); //每次进来新顾客的时候sort
                
                cout<<"erase "<<customer_vec[0]->get_customerID()<<endl;
                customer_vec.erase(customer_vec.begin());
                cout<<"````````````````````````````````"<<endl;
            }
        }

        return true;
    }
    
}



void sort_queue1_pool_and_push_to_queue1()
{
    int size = queue1_pool.size();
    // cout<<"queue1_pool.size()"<<size<<endl;
    for (int i=0; i<size; i++)
    {

        int most_prior_customer_idx = find_the_most_prior_customer(queue1_pool); // push the customer with highest priority into the queue1
        // cout<<"most_prior_customer_idx: "<<most_prior_customer_idx<<endl;
        if (most_prior_customer_idx == -1 ||queue1_pool[most_prior_customer_idx]->get_customerID()=="NULL")
        {
            break;
        }    
        else
        {
            queue1_pool[most_prior_customer_idx]->set_original_ticket_num();
            queue1_pool[most_prior_customer_idx]->set_original_priority_num();

            // cout<<"most prior customer found at index "<<most_prior_customer_idx<<endl<<endl;
            queue1.push(queue1_pool[most_prior_customer_idx]);  //缓存池进queue1
            cout<<"I pushed "<<queue1_pool[most_prior_customer_idx]->get_customerID()<<" into queue1"<<endl;
            queue1_pool.erase(queue1_pool.begin()+most_prior_customer_idx);

            // cout<<"most prior customer found!  at index "<<most_prior_customer_idx<<endl<<endl;
            //object's original variables initialisation 
            cout<<"---------------------"<<endl;
        }
    }
}


void update_priority()
{
    if (queue1.front()->get_times_of_run() % 2 == 0)
        queue1.front()->plus_update_priority();  // = priority ++
}


void works()  
{   
    timer = customer_vec[0]->get_arrival_time();
    cout<<"time begins at: "<<timer<<endl;

    //方法1
    if(check_any_new_arrival_customer_each_5_sec() == true) // somebody arrive right now
    {
        cout<<"(1) customer comes in when timer is "<< timer<<endl;
        sort_queue1_pool_and_push_to_queue1();
    }


    // 时钟
    while(true) // TIMER TIMER TIMER TIMER TIMER TIMER TIMER TIMER TIMER TIMER
    {   

        if(check_any_new_arrival_customer_each_5_sec() == true) // somebody arrive right now
        {
            cout<<"(2) customer comes in when timer is "<< timer<<endl;
            sort_queue1_pool_and_push_to_queue1();
        }

    
        // push customers from queue1_pool and sort queue1
        if(queue1_pool.size()>0)
        {
            cout<<"queue1_pool: ";
            for(int i=0; i<queue1_pool.size(); i++)
            {
                cout<<queue1_pool[i]->get_customerID()<<" ";
            }
            cout<<endl;
            // break;
            // sort_queue1_pool_and_push_to_queue1();
            cout<<"/////////////////////////////////////////////////"<<endl;
        }else
        {
            // cout<<"         |queue1_pool is empty.|                "<<endl;
        }
        
        
        if (queue1.size()>0)/////////// queue1 queue1 queue1 queue1 queue1 queue1 queue1 queue1 queue1 queue1 queue1 queue1 queue1
        {
            // cout<<"current queue1. front()"<<queue1.front()->get_customerID()<<endl;


            if(queue1.front()->get_priority() == 4)
            {
                cout<<queue1.front()->get_customerID()<<" qu le queue2."<<endl;

                //move queue1 front into queue2
                queue2.push_back(queue1.front());
                queue1.pop();
            }


            queue1.front()->add_one_time_of_run();
            // cout<<"times of run:"<<queue1.front()->get_times_of_run()<<endl;

            if (queue1.front()->get_times_of_run() == 1)
            {
                queue1.front()->set_ready_time(timer); //记录第一次头时间
                cout<<queue1.front()->get_customerID()<<"  ready time = current timer = "<<timer<<endl;
            }
            


            // sell ticket
            // cout<<"calculating N"<<endl;
            int N = ticket_quota(queue1.front()->get_priority());  //sell N tickets to customer

            if(queue1.front()->get_ticket_num()<=N) //ticket require < N
            {
                cout<<"CHU LAI LE: ------------------------>  "<<queue1.front()->get_customerID()<<endl;
                int n = queue1.front()->get_ticket_num();///////////////不能缺少
                for (int i=0; i<n; i++)
                {
                    //cout<<"queue1.front()->get_ticket_num(): "<<queue1.front()->get_ticket_num()<<endl;
                    queue1.front()->update_running_time(5);
                    queue1.front()->update_ticket_num(1);
                    timer += 5; //update timer
                    
                    if(check_any_new_arrival_customer_each_5_sec() == true) // somebody arrive right now
                    {
                        cout<<"(3) customer comes in when timer is "<< timer<<endl;
                        sort_queue1_pool_and_push_to_queue1();
                    }
                }
    
                queue1.front()->set_end(timer);
                // cout<<"||||||customer name:"<<queue1.front()->get_customerID()<<" | remain ticket num:"<<queue1.front()->get_ticket_num()<<"| N: "<<N<<endl;
                update_priority();
                cout<<"00000000000000000000000000000000000000000000000pushed "<<queue1.front()->get_customerID()<<" into output_queue.";
                output_queue.push(queue1.front()); // result goes into output_queue
                queue1.pop();


            }else if(queue1.front()->get_ticket_num()>N)  // ticket > N                       Normal case
            {   
              
                for(int i=0; i<N; i++)
                {
                    queue1.front()->update_ticket_num(1); 
                    queue1.front()->update_running_time(5);
                    timer += 5;

                    if(check_any_new_arrival_customer_each_5_sec() == true) // somebody arrive right now
                    {
                        cout<<"(4) customer comes in when timer is "<< timer<<endl;
                        sort_queue1_pool_and_push_to_queue1();
                    }
                }

                cout<<"||||||customer name:"<<queue1.front()->get_customerID()<<" | remain ticket:"<<queue1.front()->get_ticket_num()<<"| processed ticket: "<<N<<endl;
                
                update_priority();
                queue1.push(queue1.front());
                queue1.pop();
                
            }else
            {
                if(!queue1.empty()||!queue2.empty()|| timer<600)
                {
                    cout<<"manually timer +=5"<<endl;
                    timer+=5;   //manually update timer
                }else if(timer>1000)
                {
                    cout<<"break ***"<<endl;
                    break;
                }
                else
                {
                    cout<<"break ***"<<endl;
                    break;
                }
            }
            
            cout<<endl<<"important time: "<<timer<<endl;


        }
        ///////queue 2//queue 2//queue 2//queue 2//queue 2/////queue 2//queue 2//queue 2//queue 2//queue 2//queue 2//queue 2//queue 2//queue 2//queue 2//queue 2//queue 2
        else if (queue1.size()==0 && queue2.size() >0)  //执行queue2 if queue1 is empty and queue2 has customers waiting, we excute queue2
        {

            cout<<"queue2 when timer is "<<timer<<"::::::::::::";
            for (int i=0; i<queue2.size(); i++)
            {
                cout<<queue2[i]->get_customerID()<<" ";
            }
            cout<<endl;


            queue2.front()->add_one_time_of_run();
            if (queue2.front()->get_times_of_run() == 1)
            {
                queue2.front()->set_ready_time(timer); //记录第一次头时间
                // cout<<queue2.front()->get_customerID()<<"  ready time = current timer = "<<timer<<endl;
            }


            queue2 = sort_queue2(queue2);

            queue2.front()->update_ticket_num(1); // 每次只卖1张票
            queue2.front()->update_running_time(5);
            timer += 5;
            for(int i=1; i<queue2.size(); i++) //update other customers' span time in queue2
            {
                queue2[i]->update_span_time_in_queue2(5);

                if(queue2[i]->get_span_time_in_queue2() == 100)
                {   
                    queue2[i]->minus_update_priority(); // priority --
                    queue2[i] -> reset_span_time_in_queue2(); // reset span time in queue2 as 0
                    
                    if(queue2[i]->get_priority()==3)
                    {
                        // push queue2[i] into queue1_pool
                        queue1_pool.push_back(queue2[i]);
                        cout<<"queue2 push "<<queue2[i]->get_customerID()<<" to queue1 when "<<timer<<endl;
                        queue2.erase(queue2.begin()+i); //潜在bug!!!!!!!!!!!!!!!!!!!!!!!!!!!! erase野指针
                    }
                    
                }
            }
            
            
            if(queue2.front()->get_ticket_num() == 0)
            {
                queue2.front()->set_end(timer);
                // cout<<queue2.front()->get_customerID()<<" end time: "<<queue2.front()->get_end()<<endl;
                // cout<<queue2.front()->get_customerID()<<" running time: "<<queue2.front()->get_running_time()<<endl;
                // cout<<queue2.front()->get_customerID()<<" waiting time: "<<queue2.front()->get_waiting_time()<<endl;


                cout<<"CHU LAI LA------------------------when timer is:"<<timer<<"------>"<<queue2.front()->get_customerID()<<endl;
                cout<<"00000000000000000000000000000000000000000000000pushed "<<queue2.front()->get_customerID()<<" into output_queue."<<endl;
                output_queue.push(queue2.front());
                queue2.erase(queue2.begin());
            }
            


        }else
        {
            break;
        }
        
       
    }
    cout<<endl<<".................finish excution......................."<<endl;
}


void output()
{    
    int i;
    cout<<"name   arrival   end   ready   running   waiting"<<endl;    
    // for(i=0; i<result.size(); i++) // every result    

    // cout<<"queue output (from head to tail): "<<endl;
    while (!output_queue.empty())
    {
        cout<<output_queue.front()->get_customerID()<<"         ";
        cout<<output_queue.front()->get_arrival_time()<<"       ";
        cout<<output_queue.front()->get_end()<<"       ";
        cout<<output_queue.front()->get_ready_time()<<"       ";
        cout<<output_queue.front()->get_running_time()<<"      ";
        cout<<output_queue.front()->get_waiting_time()<<"      ";

        output_queue.pop();
        cout<<endl;
    }
    cout<<endl;
}


int main(int argc,char *argv[])
{    
    int i,j,k;

    freopen(argv[1], "r", stdin);  //重定向输入
    cout<<"\n\n==================== initial ========================"<<endl;
    initial();        // initial data
    
    cout<<"\n\n==================== input ========================"<<endl;
    input();         // input data 

    cout<<"\n\n==================== works ========================"<<endl;
    works();          // process data   
    cout<<"\n\n==================== output ========================"<<endl;
    output();         // output result   
    
    return 0;
}
