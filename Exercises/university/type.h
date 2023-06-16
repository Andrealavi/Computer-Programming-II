enum assetType { University, Department, Building, Room };

struct uniStructure {
	char name[51];
	assetType type;
};

typedef uniStructure infType;

int compare(infType, infType);
void copy(infType&, infType);
void print(infType);
