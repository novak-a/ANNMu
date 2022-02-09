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

#include <web/controllerFactory.hpp>


namespace web {

    namespace controllers {

        /*
         *
         * Create
         * 
         */

        annmu::mvc::Controller * ControllerFactory::create(annmu::log::Log * log, annmu::config::Config * config, annmu::http::Request * request, annmu::http::Client * client, annmu::url::Url * url, sql::Connection * db, annmu::http::Response * response, web::controllers::controllerList id) {

            if(id == web::controllers::CONTROLLER_HOMEPAGE) {
                return new web::homepage::Controller(log, config, request, client, url, db, response);
            }

            if(id == web::controllers::CONTROLLER_CONTACT) {
                return new web::contact::Controller(log, config, request, client, url, db, response);
            }
            
            return nullptr;

        }


    }

}
