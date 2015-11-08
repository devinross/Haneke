//
//  HNKNetworkFetcher.h
//  Haneke
//
//  Created by Hermes Pique on 7/23/14.
//  Copyright (c) 2014 Hermes Pique. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

@import Foundation;
@import CFNetwork;
#import "HNKCache.h"

enum
{
    HNKErrorNetworkFetcherInvalidData = -400,
    HNKErrorNetworkFetcherMissingData = -401,
    HNKErrorNetworkFetcherInvalidStatusCode = -402
};

/**
 Fetcher that can provide a network image. The key will be the absolute string of the given URL.
 */
@interface HNKNetworkFetcher : NSObject<HNKFetcher>

/**
 Initializes a fetcher with the given URL.
 @param URL Image URL.
 */
- (instancetype)initWithURL:(NSURL*)URL;


/**
 Initializes a fetcher with the given URL.
 @param URL Image URL.
 @param priority Priority of the request.
 */
- (instancetype)initWithURL:(NSURL*)URL priority:(float)priority;

/**
 Image URL.
 */
@property (nonatomic, readonly) NSURL *URL;


/*
 * Sets a scaling factor for the priority of the task. The scaling factor is a
 * value between 0.0 and 1.0 (inclusive), where 0.0 is considered the lowest
 * priority and 1.0 is considered the highest.
 *
 * The priority is a hint and not a hard requirement of task performance. The
 * priority of a task may be changed using this API at any time, but not all
 * protocols support this; in these cases, the last priority that took effect
 * will be used.
 *
 * If no priority is specified, the task will operate with the default priority
 * as defined by the constant NSURLSessionTaskPriorityDefault. Two additional
 * priority levels are provided: NSURLSessionTaskPriorityLow and
 * NSURLSessionTaskPriorityHigh, but use is not restricted to these.
 */
@property (nonatomic, readonly) float priority;



/**
 Cancels the current fetch. When a fetch is cancelled it should not call any of the provided blocks.
 @discussion This will be typically used by UI logic to cancel fetches during view reuse.
 */
- (void)cancelFetch;

@end

@interface HNKNetworkFetcher (Subclassing)

/**
 Returns the URL sessions used to download the image. Override to use a custom session. Uses sharedSession by default.
 */
@property (nonatomic, readonly) NSURLSession *URLSession;

@end
