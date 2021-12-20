namespace Reaper
{
namespace Helpers
{

}

class GUID ()
{
public:
    
    GUID ()
    {
        stringstream ss;
        std::random_device rd;
        std::mt19937 gen(rd());
        
        ss << std::hex << random (gen) << random (gen);
        value = ss.str();
        value.insert (20,"-");
        value.insert (16,"-");
        value.insert (12,"-");
        value.insert (8,"-");
    }
    
    GUID (const GUID& other)
    :
    value (other.value)
    {}
    
    String getValue () { return {value}; }
    
private:
    
    std::string value;
}

std::string value;

};
