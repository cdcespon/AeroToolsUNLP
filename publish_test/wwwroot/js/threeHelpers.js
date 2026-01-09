window.threeHelpers = {
    scene: null,
    camera: null,
    renderer: null,
    mesh: null,

    initialize: function (containerId) {
        const container = document.getElementById(containerId);
        if (!container) return;

        // Scene
        this.scene = new THREE.Scene();
        this.scene.background = new THREE.Color(0xf0f0f0);

        // Camera
        this.camera = new THREE.PerspectiveCamera(75, container.clientWidth / container.clientHeight, 0.1, 1000);
        this.camera.position.z = 2; // Default zoom

        // Renderer
        this.renderer = new THREE.WebGLRenderer({ antialias: true });
        this.renderer.setSize(container.clientWidth, container.clientHeight);
        container.appendChild(this.renderer.domElement);

        // Lights
        const light = new THREE.DirectionalLight(0xffffff, 1);
        light.position.set(1, 1, 1).normalize();
        this.scene.add(light);

        const ambientLight = new THREE.AmbientLight(0x404040);
        this.scene.add(ambientLight);

        // Resize handler
        window.addEventListener('resize', () => {
            if (this.camera && this.renderer && container) {
                this.camera.aspect = container.clientWidth / container.clientHeight;
                this.camera.updateProjectionMatrix();
                this.renderer.setSize(container.clientWidth, container.clientHeight);
            }
        });

        this.animate();
    },

    animate: function () {
        if (!this.renderer || !this.scene || !this.camera) return;

        requestAnimationFrame(() => this.animate());

        if (this.mesh) {
            this.mesh.rotation.y += 0.005; // Auto rotate slightly
        }

        this.renderer.render(this.scene, this.camera);
    },

    updateGeometry: function (vertices, indices) {
        if (!this.scene) return;

        // Remove old mesh
        if (this.mesh) {
            this.scene.remove(this.mesh);
            this.mesh.geometry.dispose();
            this.mesh.material.dispose();
        }

        const geometry = new THREE.BufferGeometry();
        geometry.setAttribute('position', new THREE.Float32BufferAttribute(vertices, 3));

        // If indices provided for faces
        if (indices && indices.length > 0) {
            geometry.setIndex(indices);
            geometry.computeVertexNormals();

            const material = new THREE.MeshPhongMaterial({
                color: 0x156289,
                emissive: 0x072534,
                side: THREE.DoubleSide,
                flatShading: true
            });

            this.mesh = new THREE.Mesh(geometry, material);
        } else {
            // Line loop for 2D profile
            const material = new THREE.LineBasicMaterial({ color: 0x0000ff });
            this.mesh = new THREE.LineLoop(geometry, material);
        }

        this.scene.add(this.mesh);
    },

    dispose: function () {
        // Cleanup logic
        // ...
        // Simplification for demo
    }
};
