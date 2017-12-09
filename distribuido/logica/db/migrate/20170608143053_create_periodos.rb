class CreatePeriodos < ActiveRecord::Migration[5.0]
  def change
    create_table :periodos do |t|
      t.integer :numero
      t.string :inicio
      t.string :termino

      t.timestamps
    end
  end
end
