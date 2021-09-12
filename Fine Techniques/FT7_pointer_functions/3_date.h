#ifndef DATE_H 
#define DATE_H
struct date
{
	int dd;
	int mm;
	int yy;
};
typedef struct date date_t;
void disp(const date_t* ptr_date);
void disp_all(const date_t* ptr_date, int n);
int compare_date(const date_t*, const date_t*);
int compare_month(const date_t*, const date_t*);
#endif
