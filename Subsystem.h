#pragma once

#include "Entity.h"
#include "ComponentTypeId.h"
#include "functions.h"

#include <vector>

using namespace std;

class Subsystem {
public:

	void use() {
		initialize_before_processing();
		processing = true;

		for (i = 0; i < entities_to_process.size(); i++) {
			process_entity(*entities_to_process[i]);
		}
		
		processing = false;
		clean_up_after_processing();
	}
	
private:
	virtual void initialize_before_processing() {}
	virtual void clean_up_after_processing() {}
	virtual void process_entity(entity& entity) {}

	virtual vector<int> define_component_type_ids() = 0;	

	void init() {
		component_type_ids = define_component_type_ids();
	}

	void add_entity(entity& entity) {
		int id = entity.get_id();

		ensure_size_of_vector(added_entities_lookup, id);
		added_entities_lookup.push_back(true);
		entities_to_process.push_back(&entity);
	}

	void remove_entity(entity& entity) {
		int id = entity.get_id();

		ensure_size_of_vector(added_entities_lookup, id + 1);

		if (added_entities_lookup[id]) {
			size_t index = index_of_item_in_vector(entities_to_process, &entity);
			bool remove_fast = true;

			added_entities_lookup[id] = false;

			if (processing) {
				if (index <= i) {
					i--;
					if (index < i) {
						remove_fast = false;
					}
				}
			}

			if (remove_fast) {
				entities_to_process[index] = entities_to_process.back();
				entities_to_process.pop_back();
			}
			else {
				entities_to_process.erase(entities_to_process.begin() + index);
			}
		}
	}

	vector<int> component_type_ids;
	vector<entity*> entities_to_process;
	vector<bool> added_entities_lookup;
	size_t i;
	bool processing;
};
