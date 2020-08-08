#pragma once

#include <libbittrex/lib/exceptions.h>
#include <algorithm>
#include <string>
#include <curl/curl.h>
#include <vector>
#include <memory>
#include <functional>

static size_t write_callback(char *contents, size_t size, size_t nmemb, void *userdata) {
    ((std::string *) userdata)->append(contents, size * nmemb);
    return size * nmemb;
}

namespace curl::options {

/**
 * Base class for libcurl options
 */
class OptionBase {
public:
    virtual ~OptionBase() = default;

    CURL *m_curlHandle;

};

/**
 * Libcurl Http header Option
 */
class HttpHeader : public OptionBase {
public:
    using curl_slist_t = std::unique_ptr<curl_slist, std::function<void(curl_slist *)>>;

    explicit HttpHeader(std::string &&header): m_header(std::move(header)) {
        m_chunk = curl_slist_t{curl_slist_append(m_chunk.get(), m_header.c_str()),
                               [](curl_slist *ptr) {
                                   curl_slist_free_all(ptr);
                               }};

    }

    inline void setOpt() {
        curl_easy_setopt(m_curlHandle, CURLOPT_HTTPHEADER, m_chunk.get());
    };

private:
    curl_slist_t m_chunk;
    std::string m_header;
};

/**
 * Libcurl WriteData Option
 */
class WriteData : public OptionBase {
public:
    explicit WriteData(std::string &buf) : m_buf(buf) {};

    inline void setOpt() {
        curl_easy_setopt(m_curlHandle, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(m_curlHandle, CURLOPT_WRITEDATA, &m_buf);
    };

private:
    std::string &m_buf;
};

/**
 * Libcurl Url Option
 */
class Url : public OptionBase {
public:
    explicit Url(std::string &&url) : m_url(std::move(url)) {};

    inline void setOpt() {
        curl_easy_setopt(m_curlHandle, CURLOPT_URL, m_url.c_str());
    };

private:
    std::string m_url;
};

} //Namespace Curl

namespace bittrex::lib {

/**
 * Wrapper class for libcurl
 */
class Curl {
public:
    Curl() {
        if (!(m_curl = curl_easy_init())) {
            throw fail("Curl init failed!");
        }
    }
    ~Curl(){
        curl_easy_cleanup(m_curl);
        std::for_each(option_list.begin(), option_list.end(), [](curl::options::OptionBase *ptr){
            delete ptr;
        });
        
        option_list.clear();
        
    }

    void perform(){
        CURLcode res;
        res = curl_easy_perform(m_curl);
        // Check for errors
        if (res != CURLE_OK) {
               std::cerr << "curl_easy_perform() failed: %s\n" << curl_easy_strerror(res) << std::endl;
        }
    }

    template<typename T, typename M>
    void setOpt(M &&option) {
        T *opt = new T{std::forward<M>(option)};
        opt->m_curlHandle = m_curl;
        opt->setOpt();
        option_list.push_back(opt);
    }

private:
    CURL *m_curl;
    std::vector<curl::options::OptionBase*> option_list;
};
} //Namespace Bittrex

