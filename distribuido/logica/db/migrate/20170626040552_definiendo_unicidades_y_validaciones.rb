class DefiniendoUnicidadesYValidaciones < ActiveRecord::Migration[5.0]
  def change
    change_column :facultades, :sigla, :string, unique: true
  end
end
