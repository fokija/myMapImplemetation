#include <iostream>
#include <vector>
#include <string>

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
class MyMap : MapInterface
{
    private:
        struct KeyValPair
        {
            std::string key;
            std::string value;
        };
        std::vector<KeyValPair> m_keyAndValues;
    public:
        void put(const std::string& key, const std::string& value) override;
        void remove(const std::string& key) override;
        std::string get(const std::string& key) override;
        int size() override;
        bool isEmpty() override;
        void clear() override;
        std::string toString() override;
};

int main()
{
    MyMap countryVsCapitalMap;
    
    countryVsCapitalMap.put("Poland", "Warsaw");
    countryVsCapitalMap.put("Germany", "Berlin");
    countryVsCapitalMap.put("Poland", "Cracow"); 
    
    std::cout << countryVsCapitalMap.toString() << "\n"; 
    std::cout << countryVsCapitalMap.size() << "\n"; 
    std::cout << countryVsCapitalMap.get("Polanndd") << "\n"; 
    std::cout << countryVsCapitalMap.get("Germany") << "\n"; 
    std::cout << (countryVsCapitalMap.isEmpty() ? "Empty" : "NotEmpty") << "\n"; 
    countryVsCapitalMap.put("France", "Paris");
    std::cout << countryVsCapitalMap.toString() << "\n"; 
    countryVsCapitalMap.remove("France");
    std::cout << countryVsCapitalMap.get("France") << "\n"; 
    std::cout << countryVsCapitalMap.size() << "\n"; 
    countryVsCapitalMap.clear();
    std::cout << countryVsCapitalMap.size() << "\n"; 
    std::cout << (countryVsCapitalMap.isEmpty() ? "Empty" : "Not empty") << "\n";
    
    return 0;
}

void MyMap::put(const std::string& key, const std::string& value) 
{
    bool ifKeyExist = false;
    int keyIndex = -1;
    for (size_t i = 0; i < m_keyAndValues.size(); i++)
    {
        if (m_keyAndValues[i].key == key)
        {
            ifKeyExist = true;
            keyIndex = i;
            break;
        }
    }
    if (ifKeyExist == true)
    {
        m_keyAndValues[keyIndex].value = value;
    }
    else
    {
        KeyValPair putKeyValPair;
        putKeyValPair.key = key;
        putKeyValPair.value = value;
        m_keyAndValues.push_back(putKeyValPair);
    }
}

void MyMap::remove(const std::string& key)
{
    bool ifKeyExist = false;
    int keyIndex = -1;
    for (size_t i = 0; i < m_keyAndValues.size(); i++)
    {
        if (m_keyAndValues[i].key == key)
        {
            ifKeyExist = true;
            keyIndex = i;
            break;
        }
    }
    if (ifKeyExist == true)
    {
        m_keyAndValues.erase(m_keyAndValues.begin() + keyIndex);
    }
    else
    {
        std::cout << "Key doesn't exist";
    }
}

std::string MyMap::get(const std::string& key) 
{
    bool ifKeyExist = false;
    int keyIndex = -1;
    for (size_t i = 0; i < m_keyAndValues.size(); i++)
    {
        if (m_keyAndValues[i].key == key)
        {
            ifKeyExist = true;
            keyIndex = i;
            break;
        }
    }

    if (ifKeyExist == true)
    {
        return m_keyAndValues[keyIndex].value;
    }
    else
    {
        return "Key doesn't exist!";
    }
}

int MyMap::size() 
{
    return m_keyAndValues.size();
}
        
bool MyMap::isEmpty() 
{
    return m_keyAndValues.empty();
}

void MyMap::clear() 
{
    m_keyAndValues.erase(m_keyAndValues.begin(), m_keyAndValues.end());
}

std::string MyMap::toString()
{
    std::string printString;
    for (size_t i = 0; i < m_keyAndValues.size(); i++)
    {
        printString += "{ " + m_keyAndValues[i].key + " : " + m_keyAndValues[i].value + " }\n";
    }
    return printString;
}