#pragma once

#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include "gl/opengl_essential.h"

#include "xml/tinyxml2.h"
#include <sstream>

namespace LGS{

class BasicConfig
{
protected:
	typedef std::map<std::string, std::string >::iterator propertiesIter;
	typedef std::map<std::string, std::string >::const_iterator propertiesConstIter;
	typedef std::pair<std::string, std::string > propertyPair;

	std::map<std::string, std::string > _properties;

public:
	BasicConfig()
	{
		_properties.clear();
	}

	BasicConfig(std::string xmlfile)
	{
		loadConfigFile(xmlfile);
	}

	bool loadConfigFile(std::string xmlfile)
	{
		tinyxml2::XMLDocument xmlDoc;
		if (xmlDoc.LoadFile(xmlfile.c_str())!=tinyxml2::XML_NO_ERROR) return false;

		tinyxml2::XMLElement * property_element = xmlDoc.FirstChildElement("BasicConfig")->FirstChildElement("property");
		while (property_element!=NULL)
		{
			std::string property_name = property_element->Attribute("name");
			std::string property_value = property_element->GetText();

			propertiesIter it = _properties.find(property_name);
			if (it!=_properties.end())
			{
				printf("Warning: duplicate properties %s defined in config file\n", property_name.c_str());
			}
			else
			{
				_properties.insert(it, propertyPair(property_name, property_value));
			}

			property_element = property_element->NextSiblingElement("property");
		}

		return true;
	}

	void get(const char* name, std::string & val) const
	{
		propertiesConstIter it = _properties.find(name);
		if (it!=_properties.end())
		{
			val = it->second;
		}
	}

	void get(const char* name, std::string & val)
	{
		propertiesIter it = _properties.find(name);
		if (it!=_properties.end())
		{
			val = it->second;
		}
	}

	void get(const char* name, bool & val) const
	{
		propertiesConstIter it = _properties.find(name);
		if (it!=_properties.end())
		{
			if (it->second.compare("True")==0)
			{
				val = true;
			}
			else
			{
				val = false;
			};
		}
	}

	void get(const char* name, bool & val)
	{
		propertiesConstIter it = _properties.find(name);
		if (it!=_properties.end())
		{
			if (it->second.compare("True")==0)
			{
				val = true;
			}
			else
			{
				val = false;
			};
		}
	}


	template <class T>
	void get(const char* name, T & val) const
	{
		propertiesConstIter it = _properties.find(name);
		if (it!=_properties.end())
		{
			std::stringstream sstream(it->second.c_str());
			sstream >> val;
		}
	}

	template <class T>
	void get(const char* name, T & val)
	{
		propertiesIter it = _properties.find(name);
		if (it!=_properties.end())
		{
			std::stringstream sstream(it->second.c_str());
			sstream >> val;
		}
	}

};

}