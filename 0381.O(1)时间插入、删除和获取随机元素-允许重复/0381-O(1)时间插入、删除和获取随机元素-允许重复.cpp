class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> Val_positions;//每个元素对应一个unordered_set存储在vector中的位置
    vector<int> nums;                                    //vector存储所有元素

    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(Val_positions[val].empty())                       //还从未在任何位置出现过
        {
            nums.push_back(val);                             //元素插入vector
            Val_positions[val].insert(nums.size()-1);        //把位置添加到该元素对应的position set中
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
    bool remove(int val) {                                   //采用“尾部元素”替换“待删除元素”的方法，然后直接删除尾部元素
        if(Val_positions[val].empty())
            return false;
        if(nums.back() == val)                               //如果vector尾部就是val，直接删除
        {
            Val_positions[val].erase(nums.size()-1);
            nums.pop_back();
        }
        else                                                 //否则需要进行尾部替换，pop尾元素操作
        {
            int tail = nums.back();
            int val_pos = *(Val_positions[val].begin());     //找到val出现的一个位置
            nums[val_pos] = tail;                            //把tail元素复制到val_pos位置上
            Val_positions[val].erase(val_pos);
            Val_positions[tail].insert(val_pos);             
            Val_positions[tail].erase(nums.size()-1);        //更新val以及tail元素的位置set
            nums.pop_back();
        }
        if(Val_positions[val].empty())                     
            Val_positions.erase(val);                        //该元素不复存在，就直接从map里面删掉
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