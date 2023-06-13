#ifndef  _RENDER_DATA_STRUCTURES_H_
#define _RENDER_DATA_STRUCTURES_H_


namespace m3d
{
	struct  Handle
	{

	};

	struct M3D_MATERIAL
	{

	};

	struct TriGroup
	{
		Handle vbHandle;
		Handle ibHandle;
		Handle materialHandle;
	};
}


#endif // _RENDER_DATA_STRUCTURES_H_
