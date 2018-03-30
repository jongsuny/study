#include <jcc.hpp>
namespace jcc {
    jcc_parse_status jcc_io::open(const char *_filename, const char *mode){
        filename = _filename;
        file = fopen(filename, mode);
        if(file == NULL) {
            return status_file_not_found;
        }
        return status_ok;
    }
    void jcc_io::close() {
        if(file != NULL) {
            fclose(file);
        }
    }
    jcc_parse_status jcc_io::size(size_t& file_size) {
        typedef long length_type;
        fseek(file, 0, SEEK_END);
        length_type length = ftell(file);
        fseek(file, 0, SEEK_SET);
        // check for I/O errors
        if (length < 0) return status_io_error;
        // check for overflow
        size_t result = static_cast<size_t>(length);
        if (static_cast<length_type>(result) != length) return status_out_of_memory;
        // finalize
        file_size = result;
        return status_ok;
    }
    jcc_parse_status jcc_io::read(jcc_buffer *buffer, size_t length) {
        // get file size (can result in I/O errors)
		size_t size = 0;
		size_t max_suffix_size = sizeof(char*);

		// allocate buffer for the whole file
		char* contents = static_cast<char*>(malloc(size + max_suffix_size));
		if (!contents) {
            return status_ok;
        }

		// read file in memory
		size_t read_size = fread(contents, 1, length, file);
        buffer->data = contents;
        buffer->size = length;
        return status_ok;
    }
    const char *jcc_io::getFileName() {
        return filename;
    }
}
