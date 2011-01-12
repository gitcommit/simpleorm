/* 
 * File:   settings.hpp
 * Author: jolo
 *
 * Created on 10. Januar 2011, 16:56
 */

#ifndef SETTINGS_HPP
#define	SETTINGS_HPP

class ConnectionData;

class Settings {
public:
    Settings();
    virtual ~Settings();

    virtual ConnectionData* connectionData() const;
private:
    Settings(const Settings& o);

    ConnectionData* _connectionData;
};

#endif	/* SETTINGS_HPP */

