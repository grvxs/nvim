return {
    {
        "wbthomason/packer.nvim",
        event = "VimEnter",
    },

    {
        "neovim/nvim-lspconfig",
        after = "nvim-lspinstall",
        config = function()
            require("_nvlx.config.lsp")
        end,
    },

    {
        "kabouzeid/nvim-lspinstall",
        event = "BufRead",
    },

    {
        "Pocco81/AutoSave.nvim",
        config = function()
            require("_nvlx.config.plugins.autosave")
        end,
        cond = function()
            return nvlx.general.autosave == true
        end,
    },

    {
        "grvxs/persistence.nvim",
        config = function()
            require("_nvlx.config.plugins.persistence")
        end,
        after = "packer.nvim",
    },

    {
        "maaslalani/nordbuddy",
        config = function()
            if require("_nvlx.colors") == false then
                vim.cmd("colorscheme " .. nvlx.general.colorscheme)
            end
        end,
        after = "packer.nvim",
    },

    {
        "norcalli/nvim-colorizer.lua",
        event = "BufRead",
        config = function()
            require("_nvlx.config.plugins.colorizer")
        end,
    },

    {
        "hrsh7th/nvim-compe",
        event = "InsertEnter",
        config = function()
            require("_nvlx.config.plugins.compe")
        end,
    },

    {
        "hrsh7th/vim-vsnip",
        event = "InsertCharPre",
    },

    {
        "rafamadriz/friendly-snippets",
        event = "InsertCharPre",
    },

    {
        "akinsho/nvim-bufferline.lua",
        config = function()
            require("_nvlx.config.plugins.bufferline")
        end,
        after = "nordbuddy",
    },

    {
        "hoob3rt/lualine.nvim",
        config = function()
            require("_nvlx.config.plugins.lualine")
        end,
        after = "nordbuddy",
    },

    {
        "nvim-treesitter/nvim-treesitter",
        event = "BufRead,BufNewFile,InsertEnter",
        config = function()
            require("_nvlx.config.plugins.treesitter")
        end,
    },

    {
        "sbdchd/neoformat",
        cmd = "Neoformat",
        config = function()
            require("_nvlx.config.plugins.neoformat")
        end,
    },

    {
        "kyazdani42/nvim-web-devicons",
        after = "plenary.nvim",
    },

    {
        "kyazdani42/nvim-tree.lua",
        cmd = "NvimTreeToggle",
        config = function()
            require("_nvlx.config.plugins.tree")
        end,
    },

    {
        "nvim-lua/plenary.nvim",
        event = "BufEnter",
    },

    {
        "nvim-lua/popup.nvim",
        after = "plenary.nvim",
    },

    {
        "nvim-telescope/telescope.nvim",
        cmd = "Telescope",
        config = function()
            require("_nvlx.config.plugins.telescope")
        end,
    },

    {
        "lewis6991/gitsigns.nvim",
        config = function()
            require("_nvlx.config.plugins.gitsigns")
        end,
        after = "plenary.nvim",
    },

    {
        "glepnir/dashboard-nvim",
        setup = function()
            require("_nvlx.config.plugins.dashboard")
        end,
        after = "packer.nvim",
    },

    {
        "windwp/nvim-autopairs",
        config = function()
            require("_nvlx.config.plugins.autopairs")
        end,
        after = "nvim-compe",
    },

    {
        "lukas-reineke/indent-blankline.nvim",
        event = "BufRead",
        setup = function()
            require("_nvlx.config.plugins.indentline")
        end,
    },

    {
        "akinsho/nvim-toggleterm.lua",
        config = function()
            require("_nvlx.config.plugins.terminal")
        end,
        after = "which-key.nvim",
    },

    {
        "folke/which-key.nvim",
        config = function()
            require("_nvlx.config.plugins.whichkey").load()
        end,
        after = "packer.nvim",
    },

    {
        "ygm2/rooter.nvim",
        config = function()
            require("_nvlx.config.plugins.rooter")
        end,
    },

    {
        "preservim/nerdcommenter",
        after = "packer.nvim",
    },
}