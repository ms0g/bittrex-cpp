#include "curl_wrapper.h"
#include "exceptions.h"

using namespace bittrex::lib;
using namespace curl::options;


static size_t write_callback(char *contents, size_t size, size_t nmemb, void *userdata) {
    ((std::string *) userdata)->append(contents, size * nmemb);
    return size * nmemb;
}

HttpHeader::HttpHeader(const std::string &header) {
    m_chunk = curl_slist_append(m_chunk, header.c_str());
}

HttpHeader::~HttpHeader() {
    curl_slist_free_all(m_chunk);
}

void HttpHeader::setOpt() {
    curl_easy_setopt(m_curlHandle, CURLOPT_HTTPHEADER, m_chunk);
}


void WriteData::setOpt() {
    curl_easy_setopt(m_curlHandle, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(m_curlHandle, CURLOPT_WRITEDATA, &m_buf);
}

void Url::setOpt() {
    curl_easy_setopt(m_curlHandle, CURLOPT_URL, m_uri.c_str());
}

CurlWrapper::CurlWrapper() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    m_curl = curl_easy_init();
    if (!m_curl)
        throw fail("Curl init failed!");
}

CurlWrapper::~CurlWrapper() {
    // always cleanup
    for (auto const &opt:m_optionList)
        delete opt;

    curl_easy_cleanup(m_curl);
    curl_global_cleanup();
}


void CurlWrapper::setOpt(curl::options::OptionBase *opt) {
    m_optionList.push_back(opt);
    opt->m_curlHandle = m_curl;
    opt->setOpt();
}

void CurlWrapper::perform() {
    m_res = curl_easy_perform(m_curl);
    // Check for errors
    if (m_res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(m_res));

}
