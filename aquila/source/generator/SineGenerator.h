/**
 * @file SineGenerator.h
 *
 * Sine wave generator.
 *
 * This file is part of the Aquila DSP library.
 * Aquila is free software, licensed under the MIT/X11 License. A copy of
 * the license is provided with the library in the LICENSE file.
 *
 * @package Aquila
 * @version 3.0.0-dev
 * @author Zbigniew Siciarz
 * @date 2007-2014
 * @license http://www.opensource.org/licenses/mit-license.php MIT
 * @since 3.0.0
 */

#ifndef SINEGENERATOR_H
#define SINEGENERATOR_H

#include "Generator.h"

namespace Aquila
{

/**
 * Sine wave generator.
 */
GeneratorClass(SineGenerator)
{
public:
	/**
	 * Creates the generator object.
	 *
	 * @param sampleFrequency sample frequency of the signal
	 */
	SineGenerator(FieldType sampleFrequency) : Generator<DataType, FieldType, Container_t>::Generator(sampleFrequency)
	{

	}

	/**
	 * Fills the buffer with generated sine samples.
	 *
	 * @param samplesCount how many samples to generate
	 */
	void generate(std::size_t samplesCount)
	{
		this->m_data.resize(samplesCount);
		FieldType normalizedFrequency = this->m_frequency /
									 static_cast<FieldType>(this->m_sampleFrequency);
		for (std::size_t i = 0; i < samplesCount; ++i)
		{
			this->m_data[i] = this->m_amplitude * std::sin(
				2.0 * M_PI * normalizedFrequency * i +
				this->m_phase * 2.0 * M_PI
			);
		}
	}
};
}

#endif // SINEGENERATOR_H
