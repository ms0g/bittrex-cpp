#ifndef BITTREX_CURL_WRAPPER_H
#define BITTREX_CURL_WRAPPER_H

#include <string>
#include <curl/curl.h>

static size_t write_callback(char *contents, size_t size, size_t nmemb, void *userdata);

namespace curl {
    namespace options {

        /**
         * Base class for libcurl options
         */
        class OptionBase {
        public:
            virtual void setOpt() = 0;
            CURL *m_curlHandle = nullptr;

        };

        /**
         * Libcurl Http header Option
         */
        class HttpHeader : public OptionBase {
        public:
            HttpHeader(const std::string &header);
            ~HttpHeader();
            void setOpt();

        private:
            struct curl_slist *m_chunk = nullptr;
        };

        /**
         * Libcurl WriteData Option
         */
        class WriteData : public OptionBase {
        public:
            WriteData(std::string &resbuf) : m_buf(resbuf) {};
            void setOpt();

        private:
            std::string &m_buf;
        };

        /**
         * Libcurl Url Option
         */
        class Url : public OptionBase {
        public:
            Url(std::string &uri) : m_uri(uri) {};
            void setOpt();

        private:
            std::string m_uri;
        };

    }
}
namespace bittrex {
    namespace lib {
        /**
         * Wrapper class for libcurl
         */
        class CurlWrapper {
        public:
            CurlWrapper();
            ~CurlWrapper();
            void perform();
            void setOpt(curl::options::OptionBase &&opt);

        private:
            CURL *m_curl;
            CURLcode m_res;
        };

    }
}


#endif //BITTREX_CURL_WRAPPER_H
