class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> Val_positions;//ÿ��Ԫ�ض�Ӧһ��unordered_set�洢��vector�е�λ��
    vector<int> nums;                                    //vector�洢����Ԫ��

    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(Val_positions[val].empty())                       //����δ���κ�λ�ó��ֹ�
        {
            nums.push_back(val);                             //Ԫ�ز���vector
            Val_positions[val].insert(nums.size()-1);        //��λ����ӵ���Ԫ�ض�Ӧ��position set��
            return true;
        }
        else
        {
            nums.push_back(val);                            
            Val_positions[val].insert(nums.size()-1);       
            return false;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {                                   //���á�β��Ԫ�ء��滻����ɾ��Ԫ�ء��ķ�����Ȼ��ֱ��ɾ��β��Ԫ��
        if(Val_positions[val].empty())
            return false;
        if(nums.back() == val)                               //���vectorβ������val��ֱ��ɾ��
        {
            Val_positions[val].erase(nums.size()-1);
            nums.pop_back();
        }
        else                                                 //������Ҫ����β���滻��popβԪ�ز���
        {
            int tail = nums.back();
            int val_pos = *(Val_positions[val].begin());     //�ҵ�val���ֵ�һ��λ��
            nums[val_pos] = tail;                            //��tailԪ�ظ��Ƶ�val_posλ����
            Val_positions[val].erase(val_pos);
            Val_positions[tail].insert(val_pos);             
            Val_positions[tail].erase(nums.size()-1);        //����val�Լ�tailԪ�ص�λ��set
            nums.pop_back();
        }
        if(Val_positions[val].empty())                     
            Val_positions.erase(val);                        //��Ԫ�ز������ڣ���ֱ�Ӵ�map����ɾ��
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int n = nums.size();
        int index = rand() % n;
        return nums[index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */