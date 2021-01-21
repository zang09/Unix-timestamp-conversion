#include <iostream>
#include <time.h>
#include <string.h>

using namespace std;

time_t makeUTCtime(int YYYY, int MM, int DD, int hh, int mi, int ss)
{
    struct tm st_tm;
    st_tm.tm_year = YYYY - 1900;
    st_tm.tm_mon = MM - 1;
    st_tm.tm_mday = DD;
    st_tm.tm_hour = hh;
    st_tm.tm_min = mi;
    st_tm.tm_sec = ss;

    return timegm(&st_tm);
}

time_t TimeFromYMD(int year, int month, int day)
{
  struct tm tm;
  memset(&tm, 0, sizeof(tm));
  tm.tm_year = year;
  tm.tm_mon = month;
  tm.tm_mday = day;
  return mktime(&tm);
}

int main()
{
    //GMT
    struct tm sample_time;
    sample_time.tm_year = 2021;
    sample_time.tm_mon = 4;
    sample_time.tm_mday = 18;
    sample_time.tm_hour = 15;
    sample_time.tm_min = 0;
    sample_time.tm_sec = 0;

    time_t utc_time = makeUTCtime(sample_time.tm_year, sample_time.tm_mon, sample_time.tm_mday,
                                  sample_time.tm_hour, sample_time.tm_min, sample_time.tm_sec);

    //time_t time_difference = difftime(TimeFromYMD(sample_time.tm_year, sample_time.tm_mon, sample_time.tm_mday), TimeFromYMD(1970, 1, 1));
    //time_difference += sample_time.tm_hour*3600 + sample_time.tm_min*60 + sample_time.tm_sec + 86400; //leap 1 day

    cout << "UTC: " << utc_time << endl;

    char res[32];
    struct tm tm;
    gmtime_r(&utc_time, &tm);
    strftime(res, sizeof(res), "%Y-%m-%d %X", &tm);
    string result(res);
    cout << "GMT: " << result << endl;

    localtime_r(&utc_time, &tm);
    strftime(res, sizeof(res), "%Y-%m-%d %X", &tm);
    string result2(res);
    cout << "My time zone: " << result2 << endl;

    return 0;
}
