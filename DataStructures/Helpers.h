namespace Reaper
{
namespace Helpers
{

}

class GUID
{
public:
    
    GUID ()
    {
        std::stringstream ss;
        ss << std::hex << Random::getSystemRandom().nextInt64 () << Random::getSystemRandom().nextInt64 ();
        
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
    
    GUID (const String& guid)
    :
    value (guid.toStdString())
    {}

    String getValue () const { return {value}; }

    bool operator== (const GUID& other) { return other.value == value; }
    bool operator!= (const GUID& other) { return !(*this == other); }
    
    operator String () const { return getValue(); }
    operator var () const { return {getValue()}; }
        
private:
    
    std::string value;
    
};

};
