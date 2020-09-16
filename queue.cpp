#include <vector>

// #include "TicketBooker.cpp"
#include "customer.cpp"
// compute N
int ticket_quota(int customer_current_priority) {return (10-customer_current_priority)*10/5;}

vector<Customer*> sort_customer_vec_based_on_arrival_time(vector<Customer*> customer_vec_)
{
    //删掉不是人的object
    for (int b=0; b<customer_vec_.size(); b++)
    {
        if(customer_vec_[b]->get_age()==999)
        {
            customer_vec_.erase(customer_vec_.begin()+b);
            b -=1;
        }
    }
    
    //sort the array by arrive time, so that the customer will arrive in order
    for (int i=0; i < customer_vec_.size()-1; i++)
    {
        for(int j=0; j < customer_vec_.size() - i - 1; j++)
        {   
            if(customer_vec_[j]->get_arrival_time() > customer_vec_[j+1] -> get_arrival_time())
            {
                swap(customer_vec_[j], customer_vec_[j+1]);
            }
        }
    }
    return customer_vec_;
}


int find_the_most_prior_customer_in_queue1_pool(vector <Customer*> queue1_pool_)  // queue1 use
{
    int min_priority = 1000;
    int min_index = -99;
    int min_arrival_time = 9000;
    int min_customerID = 1000;
    int ID = -1;

    //get minimum priority
    for (int index=0; index < queue1_pool_.size(); index++)  // array_size_: global variable
    {
        if (queue1_pool_[index]->get_priority() < min_priority)
        {
            min_priority = queue1_pool_[index]->get_priority();
            min_index = index;
        }
    }

    //get minimum arrival time
    for (int index_ = 0; index_ < queue1_pool_.size(); index_++)
    {
        if(queue1_pool_[index_]->get_priority() == min_priority && queue1_pool_[index_]->get_arrival_time() < min_arrival_time)
        {
            min_arrival_time = queue1_pool_[index_]->get_arrival_time();
            min_index = index_;
        }
    }
    //get minimim customerID
    for (int index__ = 0; index__ < queue1_pool_.size(); index__++)
    {
        ID = queue1_pool_[index__]->get_customerID()[1] - '0';

        if(queue1_pool_[index__]->get_priority() == min_priority && queue1_pool_[index__]->get_arrival_time() == min_arrival_time&& ID < min_customerID)
        {
            min_customerID = ID;
            min_index = index__;
        }
    }
    if(min_index==-1)
    {
        cout<<"min index not found!"<<endl;
        return -1; //error 
    }
    else    
    {
        queue1_pool_.erase(queue1_pool_.begin()+min_index);
        return min_index;
    }
}


int find_the_most_prior_customer_idx(vector<Customer*> customer_vec)  // and initialise original properties
{
    // cout<<"q "<<q<<endl;
    int most_prior_customer_idx = find_the_most_prior_customer_in_queue1_pool(customer_vec); // push the customer with highest priority into the queue1
    cout<<"most prior customer found!  at index "<<most_prior_customer_idx<<endl;
    if (most_prior_customer_idx == -1 ||customer_vec[most_prior_customer_idx]->get_customerID()=="NULL")
    {
        //nothing
    }else
    {
        //object's original variables initialisation 
        customer_vec[most_prior_customer_idx]->set_original_ticket_num();
        customer_vec[most_prior_customer_idx]->set_original_priority_num();
    }
    return most_prior_customer_idx;
}
    



vector<Customer*> sort_queue2(vector<Customer*> queue2_) // sort queue2 based on ticket_num > priority > arrival_time > customerID
{
    // cout<<"start sorting queue2......"<<endl;

    // cout<<"sorting queue2 based on ticket_num......"<<endl;

    //check ticket_num
    for (int i0=0; i0 < queue2_.size()-1; i0++)  // queue2_.size(): global variable
    {
        for(int j0=0; j0<queue2_.size()-i0-1; j0++)
        {
            if (queue2_[j0]->get_ticket_num() > queue2_[j0+1]->get_ticket_num())
            {
                // cout<<"queue2 "<<queue2_[j0]->get_customerID()<<" element is < than "<<queue2_[j0+1]->get_customerID()<<endl;
                swap(queue2_[j0], queue2_[j0+1]);
            }
        }
    }
    

    //check priority
    // cout<<"sorting queue2 based on priority......"<<endl;
    for (int i1=0; i1 < queue2_.size()-1; i1++)  // queue2_.size(): global variable
    {
        for(int j1=0; j1<queue2_.size()-i1-1; j1++)
        {
            if ((queue2_[j1]->get_ticket_num() == queue2_[j1+1]->get_ticket_num()))
            {
            if (queue2_[j1]->get_priority() > queue2_[j1+1]->get_priority()) //priority
                swap(queue2_[j1], queue2_[j1+1]);
            }
        }
    }

    //check arrival_time
    // cout<<"sorting queue2 based on arrival_time......"<<endl;
    for (int i2=0; i2 < queue2_.size()-1; i2++)  // queue2_.size(): global variable
    {
        for(int j2=0; j2<queue2_.size()-i2-1; j2++)
        {
            if ((queue2_[j2]->get_ticket_num() == queue2_[j2+1]->get_ticket_num()))
            {
            if (queue2_[j2]->get_priority() == queue2_[j2+1]->get_priority()) //priority
                {
                    if(queue2_[j2]->get_arrival_time() > queue2_[j2+1]->get_arrival_time())
                        swap(queue2_[j2], queue2_[j2+1]);
                }
            }
        }
    }

    //check customer_ID
    // cout<<"sorting queue2 based on CustomerID......"<<endl;
    for (int i3=0; i3 < queue2_.size()-1; i3++)  // queue2_.size(): global variable
    {
        for(int j3=0; j3<queue2_.size()-i3-1; j3++)
        {
            if ((queue2_[j3]->get_ticket_num() == queue2_[j3+1]->get_ticket_num()))
            {
            if (queue2_[j3]->get_priority() == queue2_[j3+1]->get_priority()) //priority
                {
                    if(queue2_[j3]->get_arrival_time() == queue2_[j3+1]->get_arrival_time())
                    {
                        if((queue2_[j3]->get_customerID()[1] - '0') > (queue2_[j3+1]->get_customerID()[1] - '0'))
                            swap(queue2_[j3], queue2_[j3+1]);
                    }
                }
            }
        }
    }
        
    // cout<<"finish sorting queue2"<<endl;
    return queue2_;
}




