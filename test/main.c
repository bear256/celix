/**
 *Licensed to the Apache Software Foundation (ASF) under one
 *or more contributor license agreements.  See the NOTICE file
 *distributed with this work for additional information
 *regarding copyright ownership.  The ASF licenses this file
 *to you under the Apache License, Version 2.0 (the
 *"License"); you may not use this file except in compliance
 *with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *Unless required by applicable law or agreed to in writing,
 *software distributed under the License is distributed on an
 *"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 *specific language governing permissions and limitations
 *under the License.
 */
/*
 * main.c
 *
 *  Created on: Apr 20, 2010
 *      Author: alexanderb
 */

#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers.h"
#include "bundle_activator.h"
#include "framework.h"
#include "properties.h"
#include "filter.h"
#include "bundle_context.h"
#include "bundle.h"
#include "manifest.h"
#include "version.h"
#include "version_range.h"
#include "manifest_parser.h"
#include "linkedlist.h"
#include "linked_list_iterator.h"
#include "resolver.h"
#include "hash_map.h"
#include "module.h"
#include "bundle_cache.h"
#include "constants.h"

struct bla {
    int idx;
};

typedef struct bla * bla_t;

void main_arrayTest(ARRAY_LIST list, void* *array[], int *size);

int main( int argc, const char* argv[] )
{
	// init fw etc testing
//	FRAMEWORK framework = framework_create();
// 	fw_init(framework);
// 	framework_start(framework);
//
// 	BUNDLE_CONTEXT context = framework->bundle->context;
//	BUNDLE service = bundleContext_installBundle(context, (char *) "build/bundles/receiver.zip");
//	BUNDLE service2 = bundleContext_installBundle(context, (char *) "build/bundles/receiver-2.0.zip");
//	BUNDLE list = bundleContext_installBundle(context, (char *) "build/bundles/sender.zip");
//	startBundle(list, 0);
//	startBundle(service, 0);
//	startBundle(service2, 0);

	//stopBundle(service, 0);
	//stopBundle(service2, 0);
	//stopBundle(list, 0);

//	framework_stop(framework);

    ARRAY_LIST list = arrayList_create();
    int i = 0;
    for (i = 0; i < 10; i++) {
        bla_t bl = malloc(sizeof(*bl));
        bl->idx = i;
        arrayList_add(list, bl);
    }
	bla_t *array;
	int size;
	main_arrayTest(list, (void*) &array, &size);
	printf("Idx: %d\n", array[2]->idx);
	printf("Idx: %d\n", array[9]->idx);
	printf("Idx: %d\n", array[0]->idx);


	return 0;
}

void main_arrayTest(ARRAY_LIST list, void* *array[], int *size) {
    int asize = arrayList_size(list);
    *array = malloc(asize * sizeof(*array));
    int i = 0;
    for (i = 0; i < arrayList_size(list); i++) {
        void *val = arrayList_get(list, i);
        (*array)[i] = val;
    }

}