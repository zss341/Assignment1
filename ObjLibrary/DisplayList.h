#ifndef OBJ_LIBRARY_DISPLAY_LIST_H
#define OBJ_LIBRARY_DISPLAY_LIST_H



namespace ObjLibrary
{


class DisplayList
{
public:

	static const unsigned int EMPTY;
	static const unsigned int PARTIAL;
	static const unsigned int READY;

public:
	DisplayList ();


	DisplayList (const DisplayList& original);


	~DisplayList ();


	DisplayList& operator= (const DisplayList& original);


	unsigned int getState () const;


	bool isEmpty () const;


	bool isPartial () const;


	bool isReady () const;


	void draw () const;


	void makeEmpty ();


	void begin ();


	void end ();

private:

	void copy (const DisplayList& original);

private:

	struct InnerData
	{
		unsigned int m_list_id;
		unsigned int m_usages;
	};

private:
	InnerData* mp_data;
};



}  // end of namespace ObjLibrary

#endif
