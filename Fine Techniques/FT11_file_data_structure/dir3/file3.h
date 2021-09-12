extern size_t size;
FILE* open_file(const char* fname);
void close_file(FILE *fp);
void write_file(FILE *fp, const person_t *ptr_person);
void read_file(FILE *fp, person_t *ptr_person);
void seek_file(FILE *fp, long offset);
