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


const int array_size = 20;
// const int 
// Customer* customer_arr[array_size];  // this can be seen as arrive order. array type must be Customer instead of string
Customer customer_0, customer_1, customer_2, customer_3, customer_4, customer_5, customer_6, customer_7, customer_8, customer_9,customer_10,customer_11,customer_12,customer_13,customer_14,customer_15,customer_16,customer_17,customer_18,customer_19,customer_20;
vector <Customer*> customer_vec;

vector<Customer*> queue1; // high-priority queue   priority <=3
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
        }else if(customer_arr_idx==10&&priority!="")
        {    
            customer_10 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_10);
        }else if(customer_arr_idx==11&&priority!="")
        {    
            customer_11 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_11);
        }else if(customer_arr_idx==12&&priority!="")
        {    
            customer_12 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_12);
        }else if(customer_arr_idx==13&&priority!="")
        {    
            customer_13 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_13);
        }else if(customer_arr_idx==14&&priority!="")
        {    
            customer_14 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_14);
        }else if(customer_arr_idx==15&&priority!="")
        {    
            customer_15 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_15);
        }else if(customer_arr_idx==16&&priority!="")
        {    
            customer_16 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_16);
        }else if(customer_arr_idx==17&&priority!="")
        {    
            customer_17 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_17);
        }else if(customer_arr_idx==18&&priority!="")
        {    
            customer_18 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_18);
        }else if(customer_arr_idx==19&&priority!="")
        {    
            customer_19 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_19);
        }else if(customer_arr_idx==20&&priority!="")
        {    
            customer_20 = Customer(customerID, stoi(arrival_time), stoi(priority), stoi(age), stoi(ticket_num));
            customer_vec.push_back(&customer_20);
        }else // prevent stoi error
        {
            customer_vec.push_back(&customer_20);
        }
        

        if(customer_arr_idx > array_size) 
        {
            //cout<<"customer_arr_idx bigger than array_size: "<<array_size<<endl;
            break;
        }

        //cout<<"index: "<<customer_arr_idx<<endl;
      
        //cout<<"customer_"<<customer_arr_idx<<" address:"<<&customer_vec[customer_arr_idx]<<endl;
        //cout<<"Original input: \n"<<customerID<<' '<<arrival_time<<' '<<priority<<' '<<age<<' '<<ticket_num<<endl;
        //cout<<"Processed input(read from memory): \n"<<customer_vec[customer_arr_idx]->get_customerID()<<' '<<customer_vec[customer_arr_idx]->get_arrival_time();
        // <<' '<<customer_vec[customer_arr_idx]->get_priority()<<' '<<customer_vec[customer_arr_idx]->get_age()<<' '<<customer_vec[customer_arr_idx]->get_ticket_num()<<endl;

        //cout<<"------------------------------------"<<endl;

        customer_arr_idx++;  //update customer_arr index
        
    }while (getline(cin,line));

    for (int j=0; j<customer_vec.size(); j++)
    {
        //cout<<"j:"<<j<<'|';
        //cout<<customer_vec[j]->get_customerID()<<" ";
    }
    //cout<<endl;
    //基础sort
    customer_vec = sort_customer_vec_based_on_arrival_time(customer_vec);
    //cout<<"sorted customer_vec (based on arrival_time)"<<endl;
    // for (int j=0; j<customer_vec.size(); j++)
    // {
    //     //cout<<"j:"<<j<<'|';
    //     //cout<<customer_vec[j]->get_customerID()<<" ";
    // }
}



void input()
{ 
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
            //cout<<"customer_vec[0]: "<<customer_vec[0]->get_customerID()<<endl;
            if(customer_vec[0]->get_priority() <= 3)
            {
                //cout<<"push "<<customer_vec[0]->get_customerID()<<" into queue1_pool.    ";
                queue1_pool.push_back(customer_vec[0]);     //queue1缓存池
                
                //cout<<"erase "<<customer_vec[0]->get_customerID()<<endl;
                customer_vec.erase(customer_vec.begin());
                //cout<<"````````````````````````````````"<<endl;

            }else if(customer_vec[0]->get_priority() >= 4)
            {
                //cout<<"push "<<customer_vec[0]->get_customerID()<<" into queue2.    ";
                queue2.push_back(customer_vec[0]);
                
                queue2 = sort_queue2(queue2); //每次进来新顾客的时候sort
                
                //cout<<"erase "<<customer_vec[0]->get_customerID()<<endl;
                customer_vec.erase(customer_vec.begin());
                //cout<<"````````````````````````````````"<<endl;
            }
        }

        return true;
    }
    
}



void sort_queue1_pool_and_push_to_queue1()
{
    int size = queue1_pool.size();
    // if( size < 0)
    //     //cout<<"ERROR! queue1_pool size <0 !"<<endl;
    // else
    //     //cout<<"in function sort_queue1_pool_and_push_to_queue1(), queue1_pool size: "<<size<<endl;
    

 
    for (int i=0; i<size; i++)
    {
        int most_prior_customer_idx = find_the_most_prior_customer_in_queue1_pool(queue1_pool);  // queue1 use
        if(most_prior_customer_idx <= -1)
        {
            //cout<<queue1_pool.size()<<" "<<most_prior_customer_idx<<endl;
            queue1_pool.erase(queue1_pool.begin()+most_prior_customer_idx);
        }
            
        
        // push the customer with highest priority into the queue1
        if (most_prior_customer_idx == -1 ||queue1_pool[most_prior_customer_idx]->get_customerID()=="NULL")
        {
            break;
        }    
        else
        {
            queue1_pool[most_prior_customer_idx]->set_original_ticket_num();
            queue1_pool[most_prior_customer_idx]->set_original_priority_num();

            //cout<<"most prior customer found at index "<<most_prior_customer_idx<<endl<<endl;
            queue1.push_back(queue1_pool[most_prior_customer_idx]);  //缓存池进queue1
            //cout<<"                     (I pushed "<<queue1_pool[most_prior_customer_idx]->get_customerID()<<" into queue1)"<<endl;
            queue1_pool.erase(queue1_pool.begin()+most_prior_customer_idx);

            //cout<<"most prior customer found!  at index "<<most_prior_customer_idx<<endl<<endl;
            //object's original variables initialisation 
            //cout<<"---------------------"<<endl;
        }
    }
}



void sort_queue1(int star)
{
    //cout<<"start sorting queue1......"<<endl;
    
    //check priority
    for (int i1=star; i1 < queue1.size()-1; i1++)  // queue1.size(): global variable
    {
        for(int j1=star; j1<queue1.size()-i1-1; j1++)
        {
            if (queue1[j1]->get_priority() > queue1[j1+1]->get_priority()) //priority
                swap(queue1[j1], queue1[j1+1]);
        }
    }
        
    //cout<<"finish sorting queue1"<<endl;
}


void works()  
{   
    timer = customer_vec[0]->get_arrival_time();
    //cout<<"time begins at: "<<timer<<endl;

    //方法1
    if(check_any_new_arrival_customer_each_5_sec() == true) // somebody arrive right now
    {
        //cout<<"(1) customer comes in when timer is "<< timer<<endl;
        sort_queue1_pool_and_push_to_queue1();
    }

    // 时钟
    while(true) // TIMER TIMER TIMER TIMER TIMER TIMER TIMER TIMER TIMER TIMER
    {   

        if(check_any_new_arrival_customer_each_5_sec() == true) // somebody arrive right now
        {
            //cout<<"(2) customer comes in when timer is "<< timer<<endl;
            sort_queue1_pool_and_push_to_queue1();
        }

        if(queue1_pool.size() > 0)
        {
            //cout<<"push from queue1_pool to queue1 when time ["<< timer<<"]    ";
            sort_queue1_pool_and_push_to_queue1();
        }


        // //cout<<"queue1 front: ["<<queue1_.front()->get_customerID()<<"]'s times_of_run is "<<queue1_.front()->get_times_of_run(); //cannot use

        //cout<<"queue1 when timer is ["<<timer<<"]::::::::::::";
        for (int i=0; i<queue1.size(); i++)
        {
            //cout<<queue1[i]->get_customerID()<<" ";
        }
        //cout<<endl;

        //cout<<"queue2 when timer is ["<<timer<<"]::::::::::::";
        for (int i=0; i<queue2.size(); i++)
        {
            //cout<<queue2[i]->get_customerID()<<" ";
        }
        //cout<<endl;


    
        // push customers from queue1_pool and sort queue1
        if(queue1_pool.size()>0)
        {
            //cout<<"      Who are in queue1_pool?    : ";
            for(int i=0; i<queue1_pool.size(); i++)
            {
                //cout<<queue1_pool[i]->get_customerID()<<" ";
            }
            //cout<<endl;
            // break;
        }else
        {
            //cout<<"         |queue1_pool is empty.|                "<<endl;
        }
        
        
        if (queue1.size()>0)/////////// queue1 queue1 queue1 queue1 queue1 queue1 queue1 queue1 queue1 queue1 queue1 queue1 queue1
        {

            if(queue1.front()->get_priority() == 4)
            {
                //cout<<queue1.front()->get_customerID()<<" qu le queue2."<<endl;

                //move queue1 front into queue2
                queue2.push_back(queue1.front());
                queue1.erase(queue1.begin());
            }


            queue1.front()->add_one_time_of_run();
            //cout<<"times of run:"<<queue1.front()->get_times_of_run()<<endl;

            if (queue1.front()->get_times_of_run() == 1 && queue1.front()->get_if_first_run() == false )
            {
                queue1.front()->set_ready_time(timer); //记录第一次头时间
                queue1.front()->set_if_first_run(true); //reset flag
                //cout<<"*********************"<<queue1.front()->get_customerID()<<"  ready time = current timer = "<<timer<<endl;
            }
            


            // sell ticket
            int N = ticket_quota(queue1.front()->get_priority());  //sell N tickets to customer


            if(queue1.front()->get_ticket_num()<=N) //ticket require < N
            {


                //cout<<"                                     CHU LAI LE: ------------------------>  "<<queue1.front()->get_customerID()<<endl;
                int n = queue1.front()->get_ticket_num();///////////////不能缺少
                for (int j=0; j<n; j++)
                {
                    // //cout<<"queue1.front()->get_ticket_num(): "<<queue1.front()->get_ticket_num()<<endl;
                    queue1.front()->update_running_time(5);
                    queue1.front()->update_ticket_num(1);


                    // update everyone span time in queue2 
                    for(int i=0; i<queue2.size(); i++) // start index is 0 !!!!!!!!!!
                    {
                        queue2[i]->update_span_time_in_queue2(5);
                        //cout<<"1"<<queue2[i]->get_customerID()<<"'s span time: "<<queue2[i]->get_span_time_in_queue2()<<endl;
                        if(queue2[i]->get_span_time_in_queue2() == 100)
                        {   
                            queue2[i]->minus_update_priority(); // priority --
                            queue2[i] -> reset_span_time_in_queue2(); // reset span time in queue2 as 0
                            if(queue2[i]->get_priority()==3)  //queue2有人跳车
                            {
                                // queue2[i]->set_checked(false);
                                queue1.push_back(queue2[i]);
                                //cout<<"(1) promotion occur, push"<<queue2[i]->get_customerID()<<" into queue1_pool"<<endl;
                                //cout<<"erase "<<queue2[i]->get_customerID()<<" from queue2."<<endl;
                                queue2.erase(queue2.begin()+i); // bug
                                i--;
                            }
                        }
                    }


                    timer += 5; //no problem
                    
                    if(check_any_new_arrival_customer_each_5_sec() == true) // somebody arrive right now
                    {
                        //cout<<"(3) customer comes in when timer is "<< timer<<endl;
                        sort_queue1_pool_and_push_to_queue1();
                    }
                }
                queue1.front()->set_end(timer);
                //cout<<"||||||customer name:"<<queue1.front()->get_customerID()<<" | remain ticket num:"<<queue1.front()->get_ticket_num()<<"| N: "<<N<<endl;
                
                if (queue1.front()->get_times_of_run() % 2 == 0)
                {
                    queue1.front()->plus_update_priority();  // = priority ++
                    //cout<<"(<=N) "<<queue1.front()->get_customerID()<<" times_of_run is: "<<queue1.front()->get_times_of_run();
                    //cout<<" and it's priority is updated! Now is "<<queue1.front()->get_priority()<<". ";
                }
                
                //cout<<"                                         pushed "<<queue1.front()->get_customerID()<<" into output_queue.";
                output_queue.push(queue1.front()); // result goes into output_queue
                queue1.erase(queue1.begin());


            }else if(queue1.front()->get_ticket_num()>N)  // ticket > N                       Normal case
            {   
              
                for(int j=0; j<N; j++)
                {
                    queue1.front()->update_ticket_num(1); 
                    queue1.front()->update_running_time(5);

                    // update everyone span time in queue2 
                    for(int i=0; i<queue2.size(); i++) // start index is 0 !!!!!!!!!!
                    {
                        queue2[i]->update_span_time_in_queue2(5);
                        //cout<<"2"<<queue2[i]->get_customerID()<<"'s span time: "<<queue2[i]->get_span_time_in_queue2()<<endl;
                        if(queue2[i]->get_span_time_in_queue2() == 100)
                        {   
                            queue2[i]->minus_update_priority(); // priority --
                            queue2[i] -> reset_span_time_in_queue2(); // reset span time in queue2 as 0
                            if(queue2[i]->get_priority()==3)  //queue2有人跳车
                            {
                                queue1.push_back(queue2[i]);
                                //cout<<"(2) promotion occur, push "<<queue2[i]->get_customerID()<<" into queue1 erase "<<queue2[i]->get_customerID()<<" from queue2."<<endl;
                                queue2.erase(queue2.begin()+i); //
                                i--;
                            }
                        }
                    }
                    
                    timer += 5;  // !!!!!!!!!!!  AWESOME!!!!
                    if(check_any_new_arrival_customer_each_5_sec() == true) // somebody arrive right now
                    {
                        //cout<<"(4) new customer comes in when timer is "<< timer<<endl;
                        sort_queue1_pool_and_push_to_queue1();
                        sort_queue1(1);
                    }
                    

                    if(queue1_pool.size() > 0) // somebody arrive right now
                    {
                        sort_queue1_pool_and_push_to_queue1();  ///     BUG HERE!
                        //cout<<"(4) customer comes from queue1_pool to queue1 when timer is "<< timer<<endl;
                    }
                } //买完N张票了
                //cout<<"after excution |customer name:"<<queue1.front()->get_customerID()<<"| processed ticket: "<<N<<" | remain ticket:"<<queue1.front()->get_ticket_num()<<endl;
                

                if (queue1.front()->get_times_of_run() % 2 == 0)
                {
                    queue1.front()->plus_update_priority();  // = priority ++
                    //cout<<"(>N) after excution, "<<queue1.front()->get_customerID()<<" times_of_run is: "<<queue1.front()->get_times_of_run();
                    //cout<<" and it's priority is updated! Now is "<<queue1.front()->get_priority()<<". ";
                }

                if(queue1.front()->get_priority() == 4)
                {
                    //cout<<queue1.front()->get_customerID()<<" goes to queue2."<<endl;
                    //move queue1 front into queue2
                    queue2.push_back(queue1.front());
                    queue1.erase(queue1.begin());
                }else
                {
                    //cout<<queue1.front()->get_customerID()<<" head->tail"<<endl;
                    queue1.push_back(queue1.front());
                    queue1.erase(queue1.begin());
                    sort_queue1(0);                
                }
                
                
            }
            
            //cout<<endl<<"important time in queue1: "<<timer<<endl;


        }
        ///////queue 2//queue 2//queue 2//queue 2//queue 2/////queue 2//queue 2//queue 2//queue 2//queue 2//queue 2//queue 2//queue 2//queue 2//queue 2//queue 2//queue 2
        else if (queue1.size()==0 && queue2.size() >0)  //执行queue2 if queue1 is empty and queue2 has customers waiting, we excute queue2
        {

            //cout<<"queue2 when timer is["<<timer<<"]::::::::::::";
            // for (int i=0; i<queue2.size(); i++)
            // {
            //     //cout<<queue2[i]->get_customerID()<<" ";
            // }
            //cout<<endl;
            // queue2.front()->add_one_time_of_run(); //BUG

            queue2 = sort_queue2(queue2);

            queue2.front()->update_ticket_num(1); // 每次只卖1张票
            queue2.front()->update_running_time(5);
            queue2.front()->reset_span_time_in_queue2();

            if (queue2.front()->get_if_first_run() == false)
            {
                queue2.front()->set_ready_time(timer);
                //cout<<"########################"<<queue2.front()->get_customerID()<<"  ready time = current timer = "<<timer<<endl;
                queue2.front()->set_if_first_run(true);
            }
            

            bool if_promotion = false;  //如果晋升现象出现
            
            for(int i=1; i<queue2.size(); i++) //update other customers' span time in queue2
            {
                queue2[i]->update_span_time_in_queue2(5);
                //cout<<"(3)"<<queue2[i]->get_customerID()<<"'s span time: "<<queue2[i]->get_span_time_in_queue2()<<endl;
                if(queue2[i]->get_span_time_in_queue2() == 100)
                {
                    queue2[i]->minus_update_priority(); // priority --
                    queue2[i] -> reset_span_time_in_queue2(); // reset span time in queue2 as 0
                    if(queue2[i]->get_priority()==3)  //queue2有人跳车
                    {
                        // push queue2[i] into queue1_pool
                        if(queue2[i]->get_priority()==3)  //queue2有人跳车
                        {
                            // queue2[i]->set_checked(false);
                            queue1.push_back(queue2[i]);
                            //cout<<"(3)promotion occur! push "<<queue2[i]->get_customerID()<<" into queue1 and erase "<<queue2[i]->get_customerID()<<" from queue2."<<endl;
                            queue2.erase(queue2.begin()+i); // bug
                            i--;
                        }
                    }
                }
            }

            timer += 5;


            if (if_promotion) //if promotion occur, skip current while loop process, but stay in while loop (timer)
                continue; // continue while loop

            
            if(queue2.front()->get_ticket_num() == 0)
            {
                queue2.front()->set_end(timer);
                //debug use
                //cout<<queue2.front()->get_customerID()<<" end time: "<<queue2.front()->get_end()<<endl;
                //cout<<queue2.front()->get_customerID()<<" running time: "<<queue2.front()->get_running_time()<<endl;
                //cout<<queue2.front()->get_customerID()<<" waiting time: "<<queue2.front()->get_waiting_time()<<endl;


                //cout<<"CHU LAI LA------------------------when timer is:"<<timer<<"------>"<<queue2.front()->get_customerID()<<endl;
                //cout<<"             |pushed "<<queue2.front()->get_customerID()<<" into output_queue. |"<<endl;
                output_queue.push(queue2.front());
                queue2.erase(queue2.begin());
            }
        }else
        {
            if(!queue1.empty()||!queue2.empty()|| timer<10000)
            {
                //cout<<"manually timer +=5"<<endl;
                timer += 5;   //manually update timer
            }else
            {
                //cout<<"break ***"<<endl;
                break;
            }
        }
        //cout<<"important time in queue2:"<<timer<<endl;
       
    }
    //cout<<endl<<".................finish excution......................."<<endl;
}


void output()
{    
    int i;
    cout<<"name          arrival        end        ready        running        waiting"<<endl;    
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
    //cout<<endl;
}


int main(int argc,char *argv[])
{    
    int i,j,k;

    freopen(argv[1], "r", stdin);  //重定向输入
     //cout<<"\n\n==================== initial ========================"<<endl;
    initial();        // initial data
    
    //cout<<"\n\n==================== input ========================"<<endl;
    input();         // input data 

    //cout<<"\n\n==================== works ========================"<<endl;
    works();          // process data   
    //cout<<"\n\n==================== output ========================"<<endl;
    output();         // output result   
    
    return 0;
}
////