#pragma once

namespace BAMF
{
	class gSystem
	{
	public:
		virtual void Update(float duration) = 0;
		virtual ~gSystem(void) {};
	};
}

