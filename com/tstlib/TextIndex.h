// TextIndex.h : d�claration de CTextIndex

#pragma once
#include "resource.h"       // symboles principaux

#include "comutil.h"
#include "../../textindex/textindex.h"

// ITextIndex
[
	object,
	uuid("3DF00A4D-6253-4D65-A586-6CE5E29B8980"),
	dual,	helpstring("Interface ITextIndex"),
	pointer_default(unique)
]
__interface ITextIndex : IDispatch
{
    [id(1), helpstring("method AddWord")] HRESULT AddWord([in] BSTR* word, [in] BSTR* document);
    [id(2), helpstring("method AddText")] HRESULT AddText([in] BSTR* text, [in] BSTR* document);
    [id(3), helpstring("method Pack")] HRESULT Pack(void);
    [id(4), helpstring("method FindWord")] HRESULT FindWord([in] BSTR* word);
    [id(5), helpstring("method FindText")] HRESULT FindText([in] BSTR* text,[in] LONG intersect);
    [propget, id(6), helpstring("property Version")] HRESULT Version([out, retval] BSTR* pVal);
};



// CTextIndex

[
	coclass,
	threading("apartment"),
	vi_progid("tstlib.TextIndex"),
	progid("tstlib.TextIndex.1"),
	version(1.0),
	uuid("8EC92961-CAB3-4CA6-A36E-46C39424E80B"),
	helpstring("TextIndex Class")
]
class ATL_NO_VTABLE CTextIndex : 
	public ITextIndex
{
public:
    typedef textindex<wchar_t,_bstr_t> index_type;

private:
    index_type _textindex;

public:
    CTextIndex() : _textindex()
	{
	}


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:

    STDMETHOD(AddWord)(BSTR* word, BSTR* document);
    STDMETHOD(AddText)(BSTR* text, BSTR* document);
    STDMETHOD(Pack)(void);
    STDMETHOD(FindWord)(BSTR* word);
    STDMETHOD(FindText)(BSTR* text, LONG intersect);
    STDMETHOD(get_Version)(BSTR* pVal);
};
