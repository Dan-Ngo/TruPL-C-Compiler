#include "buffer.h"

Buffer::Buffer (char *filename)
{
  // Open the file and fill the buffer.
  source.open(filename);
  if (source.fail()) {
    // Failed to open source file.
    cerr << "Can't open source file " << *filename << endl;
    buffer_fatal_error();
  }
  
  cout << "file opened\n";
}

Buffer::~Buffer()
{
	source.close();
}

void Buffer::fill_buffer()
{
	c = source.get();
	while (!source.eof() && buffer.size() < MAX_BUFFER_SIZE)
	{
		buffer.push_back(c);
		c = source.get();
	}
}

char Buffer::next_char()
{
	char nextChar = buffer.front();
	buffer.pop_front();
	return nextChar;
}

int Buffer::count()
{
	return buffer.size();
}

void Buffer::unread_char(char c)
{
	buffer.push_front(c);
}

bool Buffer::is_whitespace(char c)
{
	return (c == SPACE || c == TAB || c == NEW_LINE || c == COMMENT_MARKER);
}

void Buffer::buffer_fatal_error() const
{
  cerr << "Exiting on BUFFER FATAL ERROR" << endl;
  exit (-1);
}

