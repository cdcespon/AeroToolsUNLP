window.chartHelpers = {
    createLineChart: function (canvasId, config) {
        const ctx = document.getElementById(canvasId);
        if (!ctx) return;
        
        if (window[canvasId + '_chart']) {
            window[canvasId + '_chart'].destroy();
        }

        window[canvasId + '_chart'] = new Chart(ctx, {
            type: 'line',
            data: config.data,
            options: config.options
        });
    },
    
    createPolarChart: function (canvasId, config) {
        const ctx = document.getElementById(canvasId);
        if (!ctx) return;

         if (window[canvasId + '_chart']) {
            window[canvasId + '_chart'].destroy();
        }

        window[canvasId + '_chart'] = new Chart(ctx, {
            type: 'polarArea',
            data: config.data,
            options: config.options
        });
    },

    updateChart: function (canvasId, data) {
        const chart = window[canvasId + '_chart'];
        if (chart) {
            chart.data = data;
            chart.update();
        }
    },
    
    destroyChart: function(canvasId) {
         if (window[canvasId + '_chart']) {
            window[canvasId + '_chart'].destroy();
            delete window[canvasId + '_chart'];
        }
    }
};
