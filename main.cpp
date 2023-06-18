#include <iostream>

class MapInterface
{
    public:
      virtual void put(const std::string& key, const std::string& value) = 0;
      virtual void remove(const std::string& key) = 0;
      virtual std::string get(const std::string& key) = 0;
      virtual int size() = 0;
      virtual bool isEmpty() = 0;
      virtual void clear() = 0;
      virtual std::string toString() = 0;
};

class myMap : MapInterface
{

};

int main()
{
    
    return 0;
}