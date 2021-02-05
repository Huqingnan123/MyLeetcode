class CQueue {
public:
    CQueue() {

    }
     
    /*inջ����������ջ��push��������outջ���������ջ��pop��������һ��Ԫ�ؽ��� in ջ֮�󣬳�ջ˳�򱻷�ת��      ��Ԫ��Ҫ��ջʱ����Ҫ�Ƚ��� out ջ����ʱԪ�س�ջ˳����һ�α���ת����˳�ջ˳��ͺͿ�ʼ��ջ˳������ͬ�ģ�      �Ƚ��ȳ�������Ƕ��е�˳��*/
    stack<int> in;
    stack<int> out;

    void appendTail(int value) {
        in.push(value);
    }
    
    int deleteHead() {
        //outջ�ǿ�ʱ��ֱ�ӿ���pop��topԪ��
        if(!out.empty())
        {
            int target = out.top();
            out.pop();
            return target;   
        }
        //outջΪ��ʱ����inջ��ǰȫ��Ԫ���ƶ�������ת˳��inҲΪ�շ���-1
        else
        {
            if(in.empty())
                return -1;
            //in->outջ����˳��ķ�ת
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