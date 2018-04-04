#include "libcurlpp.h"
#include "exceptions.h"

using namespace bittrex::lib;
using namespace curl::options;


static size_t write_callback(char *contents, size_t size, size_t nmemb, void *userdata) {
    ((std::string *) userdata)->append(contents, size * nmemb);
    return size * nmemb;
}


Curl::Curl() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    m_curl = curl_easy_init();
    if (!m_curl)
        throw fail("Curl init failed!");
}


Curl::~Curl() {
    // always cleanup
    for (auto const &opt:m_optionList)
        delete opt;

    curl_easy_cleanup(m_curl);
    curl_global_cleanup();
}


void Curl::setOpt(curl::options::OptionBase *opt) {
    m_optionList.push_back(opt);
    opt->m_curlHandle = m_curl;
    opt->setOpt();
}


void Curl::perform() {
    m_res = curl_easy_perform(m_curl);
    // Check for errors
    if (m_res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(m_res));

}
