/*
 * 
 * This file is part of the ANNMu project.
 * 
 * Copyright (c) 2021-2022 Adam Novak <annmproject@protonmail.com>
 *
 * This project is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This project is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this project. If not, see https://www.gnu.org/licenses/.
 *
 * You can be released from the requirements of the license by obtaining
 * a commercial license. Getting such a license is mandatory as soon as you
 * develop commercial activities involving the ANNMu source code without
 * disclosing the source code of your own applications.
 *
 */

#ifndef ANNMu_MVC_CONTROLLER_HPP
#define ANNMu_MVC_CONTROLLER_HPP

#include <mysql_connection.h>

#include <ANNMu/config/config.hpp>
#include <ANNMu/http/request.hpp>
#include <ANNMu/http/response.hpp>
#include <ANNMu/http/client.hpp>
#include <ANNMu/log/log.hpp>
#include <ANNMu/url/url.hpp>


namespace annmu {

    namespace mvc {

        class Controller {

            protected:
                annmu::log::Log       * mLog;
                annmu::config::Config * mConfig;
                annmu::http::Request  * mRequest;
                annmu::http::Client   * mClient;
                annmu::url::Url       * mUrl;
                sql::Connection       * mDb;
                annmu::http::Response * mResponse;


            public:

                /**
                 * 
                 * @brief The constructor processes all of the data into the 
                 * appropriate class variables.
                 * 
                 * @param log It's the pointer to the log object.
                 * @param config It's the pointer to the config object.
                 * @param request It's the pointer to the request object.
                 * @param client It's the pointer to the client object.
                 * @param url It's the pointer to the url object.
                 * @param db It's the pointer to the DB object.
                 * @param response It's the pointer to the response object.
                 * 
                 */

                Controller(
                    annmu::log::Log       * log,
                    annmu::config::Config * config,
                    annmu::http::Request  * request,
                    annmu::http::Client   * client,
                    annmu::url::Url       * url,
                    sql::Connection       * db,
                    annmu::http::Response * response
                );
                

                /**
                 * 
                 * @brief The destructor will be customly implemented in each
                 * child class.
                 * 
                 */

                virtual ~Controller();


                /**
                 * 
                 * @brief The method will be customly implemented in each
                 * child class.
                 * 
                 */

                virtual void run();


                /**
                 * 
                 * @brief The method returns the string which should be printed 
                 * to the standard output.
                 * 
                 * @return The method returns the string which should be printed 
                 * to the standard output.
                 * 
                 */

                virtual std::string print();


        };
        
    }

}

#endif
