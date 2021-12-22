#pragma once

namespace Reaper
{
class Source : public ValueTreeWrapper
{
public:

	const static inline Identifier ID {"SOURCE"};

    enum Type { NONE = 0, WAVE = 1 };

	Source ();
    Source (const ValueTree& sourceTree);

    void setFile (const File& file, bool selfCallback = false) { setValue (file.getFullPathName(), FileId, selfCallback); }
    File getFile () const { return File (getValue<String> (FileId)); }
    
    void setType (const Type& newType, bool selfCallback = false) { setValue (types[(int)newType], TypeId, selfCallback); }
    Type getType () const { return (Type) types.indexOf (getValue<String> (TypeId)); }

private:

    const static inline Identifier FileId {"FILE"};
    const static inline Identifier TypeId {"Attribute0"};

    const static inline StringArray types { "NONE", "WAVE" };

	void initValueTree () override {}

};

};
