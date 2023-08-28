// particle header source

#pragma once
#include "Particle.h"
#include <stdlib.h>
#include <math.h>

namespace kribsplosion
{

	struct Particle 
	{
		double m_x;
		double m_y;

	private:
		double m_speed;
		double m_direction;

	private:
		void init();

	public:
		Particle();
		virtual ~Particle();
		void update(int interval);
	};
}



