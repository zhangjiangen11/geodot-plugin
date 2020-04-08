#include "Feature.h"

#include <gdal/ogr_feature.h>

Feature::Feature(OGRFeature *feature) : feature(feature) {}

std::map<std::string, std::string> Feature::get_attributes() {
    std::map<std::string, std::string> ret;

    for (auto &&oField: *feature) {
        ret[oField.GetName()] = oField.GetAsString();
    }

    return ret;
}

const char *Feature::get_attribute(const char *name) {
    return feature->GetFieldAsString(name);
}