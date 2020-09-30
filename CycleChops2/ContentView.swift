//
//  ContentView.swift
//  CycleChops2
//
//  Created by Toby Gundry on 26/9/20.
//  Copyright © 2020 Toby Gundry. All rights reserved.
//

import SwiftUI

struct SensorDatumView : View {
    let title: String
    let value: String
    
    var body: some View {
        VStack() {
            Text(title)
                .fontWeight(Font.Weight.bold)
                .font(Font.custom("Helvetica", size: 32.0))
                .foregroundColor(Color.init(red: 0.0, green: 46/255, blue: 108/255))
            Text(value)
                .font(Font.custom("Helvetica", size: 72.0))
                .foregroundColor(Color.init(red: 0.0, green: 167/255, blue: 206/255))
        }
    }
}

struct ContentView: View {
    @ObservedObject var bikeManager: BikeManager = BikeManager()
    init() {
        bikeManager.discoverAndConnect()
    }
    var body: some View {
        VStack() {
            Spacer()
            HStack() {
                Spacer()
                SensorDatumView(title: "Speed", value: bikeManager.formattedSpeed)
                Spacer()
                SensorDatumView(title: "Cadence", value: bikeManager.formattedCadence)
                Spacer()
            }
            Spacer()
            HStack() {
                Spacer()
                SensorDatumView(title: "Distance", value: bikeManager.formattedDistance)
                Spacer()
                SensorDatumView(title: "Wheel revolutions", value: String(bikeManager.wheelRevolutions))
                Spacer()
            }
            Spacer()
        }.background(bikeManager.isCoasting ? Color.red : Color.clear)
    }
}
