#ifndef BITTREX_LIBCURLPP_H
#define BITTREX_LIBCURLPP_H

#include <string>
#include <curl/curl.h>
#include <vector>
#include <memory>
#include <functional>

size_t write_callback(char *contents, size_t size, size_t nmemb, void *userdata);


namespace curl { namespace options {

/**
 * Base class for libcurl options
 */
class OptionBase {
public:
    virtual ~OptionBase() = default;

    virtual void setOpt() = 0;

    std::shared_ptr<CURL> m_curlHandle;

};

/**
 * Libcurl Http header Option
 */
class HttpHeader : public OptionBase {
public:
    using curl_slist_t = std::unique_ptr<curl_slist, std::function<void(curl_slist *)>>;

    explicit HttpHeader(const std::string &header) {
        m_chunk = curl_slist_t(curl_slist_append(m_chunk.get(), header.c_str()),
                               [](curl_slist *ptr) {
                                   curl_slist_free_all(ptr);
                               });

    }

    inline void setOpt() override {
        curl_easy_setopt(m_curlHandle.get(), CURLOPT_HTTPHEADER, m_chunk.get());
    };

private:
    curl_slist_t m_chunk;
};

/**
 * Libcurl WriteData Option
 */
class WriteData : public OptionBase {
public:
    explicit WriteData(std::string &buf) : m_buf(buf) {};

    inline void setOpt() override {
        curl_easy_setopt(m_curlHandle.get(), CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(m_curlHandle.get(), CURLOPT_WRITEDATA, &m_buf);
    };

private:
    std::string &m_buf;
};

/**
 * Libcurl Url Option
 */
class Url : public OptionBase {
public:
    explicit Url(std::string &url) : m_url(url) {};

    inline void setOpt() override {
        curl_easy_setopt(m_curlHandle.get(), CURLOPT_URL, m_url.c_str());
    };

private:
    std::string &m_url;
};

}} //Namespace Curl

namespace bittrex { namespace lib {
/**
 * Wrapper class for libcurl
 */
class Curl {
public:
    Curl();

    void perform();

    void setOpt(std::shared_ptr<curl::options::OptionBase>);

private:
    std::shared_ptr<CURL> m_curl;
    CURLcode m_res;
};
}} //Namespace Bittrex


#endif //BITTREX_LIBCURLPP_H
