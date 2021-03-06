//
// Created by arno on 22/12/2019.
//

#ifndef SPACEINVADERS_LOADER_H
#define SPACEINVADERS_LOADER_H

#include <string>

#include "../../rapidjson/document.h"
#include "../Observer/Observable.h"

namespace spaceinvaders::loader {
class Loader : public observer::Observable
{
private:
        std::string filename;

public:
        /**
         * Create a loader for a specific file
         * @param filename The json file you want to read  (in the levels folder)
         */
        explicit Loader(const std::string& filename);

        /**
         * Get a rapidjson document for the file
         * @return Rapidjson document corresponding to the provided json file
         */
        [[nodiscard]] rapidjson::Document getDocument() const;

        /**
         * Get the provided json file
         * @return a string containing the name of the file
         */
        [[nodiscard]] const std::string& getFilename() const;

        /**
         * Check whether given attribute is in the document
         * @param input The name of the rapidjson document
         * @param attributeName The name of the attribute
         * @param onlyCheckExists Check only if the attribute is not null
         * @param checkNum Check whether the attribute is a number, else there will be checked whether the attribute is
         * a string
         */
        static void checkAttribute(const rapidjson::Document& input, const std::string& attributeName,
                                   bool checkNum = false, bool onlyCheckExists = false);
};
} // namespace spaceinvaders::loader

#endif // SPACEINVADERS_LOADER_H
