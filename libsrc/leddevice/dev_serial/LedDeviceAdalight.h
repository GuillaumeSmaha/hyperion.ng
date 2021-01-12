#ifndef LEDEVICETADALIGHT_H
#define LEDEVICETADALIGHT_H

// hyperion includes
#include "ProviderRs232.h"

///
/// Implementation of the LedDevice interface for writing to an Adalight LED-device.
///
class LedDeviceAdalight : public ProviderRs232
{
	Q_OBJECT

public:

	///
	/// @brief Constructs an Adalight LED-device
	///
	/// @param deviceConfig Device's configuration as JSON-Object
	///
	explicit LedDeviceAdalight(const QJsonObject &deviceConfig);

	///
	/// @brief Constructs the LED-device
	///
	/// @param[in] deviceConfig Device's configuration as JSON-Object
	/// @return LedDevice constructed
	static LedDevice* construct(const QJsonObject &deviceConfig);


private:

	///
	/// @brief Initialise the device's configuration
	///
	/// @param[in] deviceConfig the JSON device configuration
	/// @return True, if success
	///
	bool init(const QJsonObject &deviceConfig) override;

	///
	/// @brief Writes the RGB-Color values to the LEDs.
	///
	/// @param[in] ledValues The RGB-color per LED
	/// @return Zero on success, else negative
	///
	int write(const std::vector<ColorRgb> & ledValues) override;

	///
	/// @brief Switch the LEDs on relay.
	///
	/// @return Zero on success, else negative
	///
	bool powerOn() override;

	///
	/// @brief Switch the LEDs off relay.
	///
	/// @return Zero on success, else negative
	///
	bool powerOff() override;


	const short _headerSize;
	bool        _relayIsEnabled;
	bool        _ligthBerryAPA102Mode;
};

#endif // LEDEVICETADALIGHT_H
