#ifndef BITTREX_LIBCURLPP_H
#define BITTREX_LIBCURLPP_H

#include <string>
#include <curl/curl.h>
#include <vector>

static size_t write_callback(char *contents, size_t size, size_t nmemb, void *userdata);

namespace curl {
    namespace options {

        /**
         * Base class for libcurl options
         */
        class OptionBase {
        public:
            virtual ~OptionBase() = default;
            virtual void setOpt() = 0;
            CURL *m_curlHandle = nullptr;

        };

        /**
         * Libcurl Http header Option
         */
        class HttpHeader : public OptionBase {
        public:
            explicit HttpHeader(const std::string &header) {
                m_chunk = curl_slist_append(m_chunk, header.c_str());
            }

            ~HttpHeader() override {
                curl_slist_free_all(m_chunk);
            }

            inline void setOpt() override {
                curl_easy_setopt(m_curlHandle, CURLOPT_HTTPHEADER, m_chunk);
            };

        private:
            struct curl_slist *m_chunk = nullptr;
        };

        /**
         * Libcurl WriteData Option
         */
        class WriteData : public OptionBase {
        public:
            explicit WriteData(std::string &buf) : m_buf(buf) {};

            inline void setOpt() override {
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
            explicit Url(std::string &url) : m_url(url) {};

            inline void setOpt() override {
                curl_easy_setopt(m_curlHandle, CURLOPT_URL, m_url.c_str());
            };

        private:
            std::string &m_url;
        };

    }
}
namespace bittrex {
    namespace lib {
        /**
         * Wrapper class for libcurl
         */
        class Curl {
        public:
            Curl();
            ~Curl();

            void perform();
            void setOpt(curl::options::OptionBase *opt);

        private:
            CURL *m_curl;
            CURLcode m_res;
            std::vector<curl::options::OptionBase *> m_optionList;
        };

    }
}


#endif //BITTREX_LIBCURLPP_H
