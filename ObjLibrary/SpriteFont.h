
#ifndef OBJ_LIBRARY_SPRITE_FONT_H
#define OBJ_LIBRARY_SPRITE_FONT_H

#include <string>
#include <vector>



namespace ObjLibrary
{

class SpriteFont
{
public:

	static const unsigned int NO_BREAK_NEEDED;

	static const unsigned int PLAIN;
	static const unsigned int BOLD ;
	static const unsigned int MIRROR;
	static const unsigned int ITALICS;
	static const unsigned int SLANT;
	static const unsigned int BACK_ITALICS;
	static const unsigned int UNDERLINE;
	static const unsigned int DOUBLE_UNDERLINE;
	static const unsigned int RED_UNDERLINE;
	static const unsigned int STRIKETHROUGH;
	static const unsigned int DOUBLE_STRIKETHROUGH;
	static const unsigned int RED_STRIKETHROUGH;
	static const unsigned int WIDE;
	static const unsigned int VERY_WIDE;
	static const unsigned int NARROW;


	static bool isAPowerOf2 (unsigned int n);

	static bool isValidFormat (unsigned int format);

	static bool is2dViewSetUp ();

	static void setUp2dView (int width, int height);


	static void unsetUp2dView ();

public:
//
//  Default Constructor
//
//  Purpose: To create a new SpriteFont with no image specified.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: A new uninitalized SpriteFont is created.
//

	SpriteFont ();

	SpriteFont (const char* a_image,
		    unsigned char red, unsigned char green,
		    unsigned char blue);
	SpriteFont (const std::string& image,
		    unsigned char red, unsigned char green,
		    unsigned char blue);

//
//  Destructor
//
//  Purpose: To safely destroy a SpriteFont without memory
//	     leaks.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: All dynamically alloacted memory is freed.
//		 This include video memory.
//

	~SpriteFont ();

//
//  isInitalized
//
//  Purpose: To determine if this SpriteFont is initalized.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: Whether this SpriteFont is intalized.
//  Side Effect: N/A
//

	bool isInitalized () const;

//
//  is8Bit
//
//  Purpose: To determine if this SpriteFont is an 8-bit font,
//	     with 256 characters, instead of a 7-bit font, with
//	     128 characters.
//  Parameter(s): N/A
//  Precondition(s):
//	<1> isInitalized()
//  Returns: Whether this SpriteFont is a 8-bit font.
//  Side Effect: N/A
//

	bool is8Bit () const;

//
//  getHeight
//
//  Purpose: To determine the height of a character in this
//	     SpriteFont.
//  Parameter(s):
//	<1> format: The text format
//  Precondition(s):
//	<1> isInitalized()
//	<2> isValidFormat(format)
//  Returns: The height of a character in this SpriteFont with
//	     formatting format.
//  Side Effect: N/A
//

	int getHeight () const;
	int getHeight (unsigned int format) const;

//
//  getWidth
//
//  Purpose: To determine the width of the specifed character in
//	     this SpriteFont if displayed with the specified
//	     formatting.  If no formatting is specified, PLAIN
//	     formatting is assumed.
//  Parameter(s):
//	<1> character: The character
//	<2> format: The text format
//  Precondition(s):
//	<1> isInitalized()
//	<2> isValidFormat(format)
//  Returns: The width of character in this SpriteFont with
//	     formatting format.
//  Side Effect: N/A
//

	int getWidth (char character) const;
	int getWidth(char character, unsigned int format) const;

//
//  getWidth
//
//  Purpose: To determine the width of the specifed string when
//	     displayed with this this SpriteFont with the
//	     specified formatting.  If no formatting
//	     is specified, PLAIN formatting is assumed.
//  Parameter(s):
//	<1> a_str: The NULL-terminated string
//	<1> str: The string
//	<2> format: The text format
//  Precondition(s):
//	<1> isInitalized()
//	<2> isValidFormat(format)
//	<3> a_str != NULL
//  Returns: The width of a_str/str in this SpriteFont with
//	     formatting format.
//  Side Effect: N/A
//

	int getWidth (const char* a_str) const;
	int getWidth (const std::string& str) const;
	int getWidth (const char* a_str,
		      unsigned int format) const;
	int getWidth (const std::string& str,
		      unsigned int format) const;

//
//  getBreakPoint
//
//  Purpose: To determine where a string should be broken to
//	     make lines of the specified width when it is
//	     displayed in this SpriteFont with the specified
//	     formatting.  If no formatting is specified, PLAIN
//	     formatting is assumed.
//  Parameter(s):
//	<1> a_str: The NULL-terminated string to break
//	<1> str: The string to break
//	<2> width: The width of a line
//	<3> format: The text format
//  Precondition(s):
//	<1> isInitalized()
//	<2> isValidFormat(format)
//	<3> a_str != NULL
//  Returns: The character after which a_str/str, if displayed
//	     with this SpriteFont and formatting format, should
//	     be broken and continue on the next line.  If
//	     a_str/str is short enough to fit on one line,
//	     NO_BREAK_NEEDED is returned.
//  Side Effect: N/A
//

	unsigned int getBreakPoint (const char* a_str,
				    unsigned int width) const;
	unsigned int getBreakPoint (const std::string& str,
				    unsigned int width) const;
	unsigned int getBreakPoint (const char* a_str,
				    unsigned int width,
				    unsigned int format) const;
	unsigned int getBreakPoint (const std::string& str,
				    unsigned int width,
				    unsigned int format) const;

//
//  breakString
//
//  Purpose: To break a string into a vector of strings with
//	     lines of the specified width when displayed in this
//	     SpriteFont with the specified formatting.  If no
//	     formatting is specified, PLAIN formatting is
//	     assumed.
//  Parameter(s):
//	<1> a_str: The NULL-terminated string to break
//	<1> str: The string to break
//	<2> width: The width of a line
//	<3> format: The text format
//  Precondition(s):
//	<1> isInitalized()
//	<2> isValidFormat(format)
//	<3> a_str != NULL
//  Returns: A vector containing the lines that a_str/str, if
//	     displayed with this SpriteFont and formatting
//	     format, should be broken into.
//  Side Effect: N/A
//

	std::vector<std::string> breakString (
				      const char* a_str,
				      unsigned int width) const;
	std::vector<std::string> breakString (
				      const std::string& str,
				      unsigned int width) const;
	std::vector<std::string> breakString (
				     const char* a_str,
				     unsigned int width,
				     unsigned int format) const;
	std::vector<std::string> breakString (
				     const std::string& str,
				     unsigned int width,
				     unsigned int format) const;

//
//  draw
//
//  Purpose: To draw the specified string with the specified
//	     formatting in white at the specified position using
//	     this SpriteFont.
//  Parameter(s):
//	<1> a_str: The NULL-terminated string to draw
//	<1> str: The string to break
//	<2> x
//	<3> y: The top left corner of the string
//	<4> format: The text format
//  Precondition(s):
//	<1> isInitalized()
//	<2> isValidFormat(format)
//	<3> a_str != NULL
//  Returns: N/A
//  Side Effect: String a_str/str is drawn in white at position
//		 (x, y) and with formatting format.  a_str/str
//		 is drawn on the XY-plane with -Y as up and each
//		 character to the +X of the previous one.
//

	void draw (const char* a_str,
		   double x, double y) const;
	void draw (const std::string& str,
		   double x, double y) const;
	void draw (const char* a_str,
		   double x, double y,
		   unsigned int format) const;
	void draw (const std::string& str,
		   double x, double y,
		   unsigned int format) const;

//
//  draw
//
//  Purpose: To draw the specified string with the specified
//	     formatting in the specified colour at the specified
//	     position using this SpriteFont.
//  Parameter(s):
//	<1> a_str: The NULL-terminated string to draw
//	<1> str: The string to break
//	<2> x
//	<3> y: The top left corner of the string
//	<4> red
//	<5> green
//	<6> blue: The colour to draw the string with
//	<7> format: The text format
//	<8> alpha: The transparency to draw the string with
//  Precondition(s):
//	<1> isInitalized()
//	<2> isValidFormat(format)
//	<3> a_str != NULL
//  Returns: N/A
//  Side Effect: String a_str/str is drawn in colour
//		 (red, green, blue) and with formatting format
//		 at position (x, y).  a_str/str is drawn on the
//		 XY-plane with -Y as up and each character to
//		 the +X of the previous one.
//

	void draw (const char* a_str,
		   double x, double y,
		   unsigned char red,
		   unsigned char green,
		   unsigned char blue) const;
	void draw (const std::string& str,
		   double x, double y,
		   unsigned char red,
		   unsigned char green,
		   unsigned char blue) const;
	void draw (const char* a_str,
		   double x, double y,
		   unsigned char red,
		   unsigned char green,
		   unsigned char blue,
		   unsigned int format) const;
	void draw (const std::string& str,
		   double x, double y,
		   unsigned char red,
		   unsigned char green,
		   unsigned char blue,
		   unsigned int format) const;
	void draw (const char* a_str,
		   double x, double y,
		   unsigned char red,
		   unsigned char green,
		   unsigned char blue,
		   unsigned int format,
		   unsigned char alpha) const;
	void draw (const std::string& str,
		   double x, double y,
		   unsigned char red,
		   unsigned char green,
		   unsigned char blue,
		   unsigned int format,
		   unsigned char alpha) const;

//
//  draw
//
//  Purpose: To draw the specified vector of strings with the
//	     specified formatting in white at the specified
//	     position using this SpriteFont.
//  Parameter(s):
//	<1> lines: The vector of strings
//	<2> x
//	<3> y: The top left corner of the string
//	<4> format: The text format
//  Precondition(s):
//	<1> isInitalized()
//	<2> isValidFormat(format)
//  Returns: N/A
//  Side Effect: The strings in lines are drawn in white as
//		 successive lines of text starting at position
//		 (x, y) and with formatting format.  The strings
//		 is drawn on the XY-plane with -Y as up and each
//		 character to the +X of the previous one and
//		 each line to the +Y of the previous one.
//

	void draw (const std::vector<std::string>& lines,
		   double x, double y) const;
	void draw (const std::vector<std::string>& lines,
		   double x, double y,
		   unsigned int format) const;

//
//  draw
//
//  Purpose: To draw the specified vector of strings with the
//	     specified formatting in the specified colour at the
//	     specified position using this SpriteFont.
//  Parameter(s):
//	<1> lines: The vector of strings
//	<2> x
//	<3> y: The top left corner of the string
//	<4> red
//	<5> green
//	<6> blue: The colour to draw the string with
//	<7> format: The text format
//	<8> alpha: The transparency to draw the string with
//  Precondition(s):
//	<1> isInitalized()
//	<2> isValidFormat(format)
//  Returns: N/A
//  Side Effect: The strings in lines are drawn in colour
//		 (red, green, blue) as successive lines of text
//		 starting at position (x, y) and with formatting
//		 format.  The strings is drawn on the XY-plane
//		 with -Y as up and each character to the +X of
//		 the previous one and each line to the +Y of the
//		 previous one.
//

	void draw (const std::vector<std::string>& lines,
		   double x, double y,
		   unsigned char red,
		   unsigned char green,
		   unsigned char blue) const;
	void draw (const std::vector<std::string>& lines,
		   double x, double y,
		   unsigned char red,
		   unsigned char green,
		   unsigned char blue,
		   unsigned int format) const;
	void draw (const std::vector<std::string>& lines,
		   double x, double y,
		   unsigned char red,
		   unsigned char green,
		   unsigned char blue,
		   unsigned int format,
		   unsigned char alpha) const;

//
//  load
//
//  Purpose: To initalize this SpriteFont with the font in the
//	     specified file.
//  Parameter(s):
//	<1> a_image: The file name of the font image
//	<1> image: The file name of the font image
//  Precondition(s):
//	<1> !isInitalized()
//	<2> a_image != NULL
//	<3> File a_image exists
//	<4> File a_image is a valid 24-bit of 32-bit bitmap file
//	<5> The width of image/a_image is at least 16
//	<6> The width of image/a_image is a power of 2
//	<7> The height of image/a_image is equal to exactly or
//	    half of the width of image/a_image
//  Returns: N/A
//  Side Effect: This SpriteFont is initialized with image
//		 a_image/image. The colour magenta is used to
//		 indicate the size of the characters.
//

	void load (const char* a_image);
	void load (const std::string& image);

//
//  load
//
//  Purpose: To initalize this SpriteFont with the font in the
//	     specified file.
//  Parameter(s):
//	<1> a_image: The file name of the font image
//	<1> image: The file name of the font image
//	<2> red
//	<3> green
//	<4> blue: The colour indicating the size of the
//		  characters in the font
//  Precondition(s):
//	<1> !isInitalized()
//	<2> a_image != NULL
//	<3> File a_image exists
//	<4> File a_image is a valid 24-bit of 32-bit bitmap file
//	<5> The width of image/a_image is at least 16
//	<6> The width of image/a_image is a power of 2
//	<7> The height of image/a_image is equal to exactly or
//	    half of the width of image/a_image
//	<8> red != green || red != blue
//  Returns: N/A
//  Side Effect: This SpriteFont is initialized with image
//		 a_image/image. The colour (red, green, blue) is
//		 used to indicate the size of the characters.
//

	void load (const char* a_image,
		   unsigned char red, unsigned char green,
		   unsigned char blue);
	void load (const std::string& image,
		   unsigned char red, unsigned char green,
		   unsigned char blue);

private:
//
//  Copy Constructor
//  Assignment Operator
//
//  These functions have intentionally not been implemented
//    because video memory should not be copied.
//

	SpriteFont (const SpriteFont& original);
	SpriteFont& operator= (const SpriteFont& original);

//
//  Helper Function: invariant
//
//  Purpose: To determine if the class invariant is true.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: Whether the class invariant is true.
//  Side Effect: N/A
//

	bool invariant () const;

private:
	unsigned int m_character_count;
	unsigned int m_image_size;
	unsigned int m_character_height;
	unsigned int ma_character_name[0x100];
	unsigned int ma_character_width[0x100];
};



}  // end of namespace ObjLibrary

#endif
