class CQueue {
public:
    CQueue() {

    }
     
    /*in栈用来处理入栈（push）操作，out栈用来处理出栈（pop）操作。一个元素进入 in 栈之后，出栈顺序被反转。      当元素要出栈时，需要先进入 out 栈，此时元素出栈顺序再一次被反转，因此出栈顺序就和开始入栈顺序是相同的，      先进先出，这就是队列的顺序。*/
    stack<int> in;
    stack<int> out;

    void appendTail(int value) {
        in.push(value);
    }
    
    int deleteHead() {
        //out栈非空时，直接可以pop出top元素
        if(!out.empty())
        {
            int target = out.top();
            out.pop();
            return target;   
        }
        //out栈为空时，将in栈当前全部元素移动过来反转顺序，in也为空返回-1
        else
        {
            if(in.empty())
                return -1;
            //in->out栈进行顺序的反转
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
            int target = out.top();
            out.pop();
            return target;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */