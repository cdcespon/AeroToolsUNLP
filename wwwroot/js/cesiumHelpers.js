window.cesiumHelpers = {
    viewer: null,

    initialize: function (containerId) {
        // Use OpenStreetMap imagery provider to avoid Ion token requirement for basic functionality
        // Or user can provide token later.

        // Disable default widgets for cleaner UI
        this.viewer = new Cesium.Viewer(containerId, {
            terrainProvider: undefined, // Default terrain requires token usually
            baseLayerPicker: false,
            geocoder: false,
            homeButton: false,
            infoBox: false,
            sceneModePicker: false,
            selectionIndicator: false,
            timeline: false,
            navigationHelpButton: false,
            animation: false,
            imageryProvider: new Cesium.TileMapServiceImageryProvider({
                url: Cesium.buildModuleUrl('Assets/Textures/NaturalEarthII')
            }),
        });

        // Enable depth test for proper 3D rendering
        this.viewer.scene.globe.depthTestAgainstTerrain = false;
    },

    addEntity: function (entityJson) {
        if (!this.viewer) return;

        try {
            const options = JSON.parse(entityJson);

            // Handle position conversion
            if (options.position && options.position.cartographicDegrees) {
                const degs = options.position.cartographicDegrees;
                options.position = Cesium.Cartesian3.fromDegrees(degs[0], degs[1], degs[2]);
            }

            // Convert color strings to Cesium.Color if present
            if (options.polygon && options.polygon.material) {
                options.polygon.material = Cesium.Color.fromCssColorString(options.polygon.material);
            }
            if (options.cylinder && options.cylinder.material) {
                options.cylinder.material = Cesium.Color.fromCssColorString(options.cylinder.material);
            }
            if (options.polyline && options.polyline.material) {
                options.polyline.material = Cesium.Color.fromCssColorString(options.polyline.material);
            }

            const entity = this.viewer.entities.add(options);
            this.viewer.zoomTo(entity);
        } catch (e) {
            console.error("Error adding entity", e);
        }
    },

    clearEntities: function () {
        if (this.viewer) {
            this.viewer.entities.removeAll();
        }
    },

    flyTo: function (lat, lon, height) {
        if (!this.viewer) return;
        this.viewer.camera.flyTo({
            destination: Cesium.Cartesian3.fromDegrees(lon, lat, height)
        });
    },

    getCameraPosition: function () {
        if (!this.viewer) return null;
        var cartographic = this.viewer.camera.positionCartographic;
        return {
            longitude: Cesium.Math.toDegrees(cartographic.longitude),
            latitude: Cesium.Math.toDegrees(cartographic.latitude),
            height: cartographic.height
        };
    },

    destroy: function () {
        if (this.viewer) {
            this.viewer.destroy();
            this.viewer = null;
        }
    }
};

window.downloadFileFromText = function (filename, text) {
    var element = document.createElement('a');
    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(text));
    element.setAttribute('download', filename);

    element.style.display = 'none';
    document.body.appendChild(element);

    element.click();

    document.body.removeChild(element);
};
