//
//  TraceRoute.h
//  Classe implémentant les fonctionnalités d'un traceroute. 
//
//  Created by Christophe Janot on 06/06/13.
//  Copyright (c) 2013 Christophe Janot. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Hop.h"

static const int TRACEROUTE_PORT     = 80;
static const int TRACEROUTE_MAX_TTL  = 20;
static const int TRACEROUTE_ATTEMPTS = 5;
static const int TRACEROUTE_TIMEOUT  = 1000000;

// Delégation afin de notifier chaque nouveau hop découvert pour chaque TTL.
@protocol TraceRouteDelegate

- (void)newHop:(Hop *)hop;
- (void)end;

@end

@interface TraceRoute : NSObject{
    
    int udpPort;
    int maxTTL;
    int readTimeout;
    int maxAttempts;
    NSString *running;
    bool isrunning;
}

@property (nonatomic, weak) id<TraceRouteDelegate> delegate;

- (TraceRoute *)initWithMaxTTL:(int)ttl timeout:(int)timeout maxAttempts:(int)attempts port:(int)port;
- (void)doTraceRouteToHost:(NSString *)host maxTTL:(int)ttl timeout:(int)timeout maxAttempts:(int)attempts port:(int)port;
- (void)doTraceRouteToHost:(NSString *)host;
- (void)stopTrace;
- (int)hopsCount;
- (bool)isRunning;

@end
